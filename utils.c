/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   utils.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kangjaehyun <kangjaehyun@student.42.fr>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/29 15:16:41 by jae-kang		  #+#	#+#			 */
/*   Updated: 2024/11/24 00:01:45 by kangjaehyun	  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(char *msg, t_mlx *mlx)
{
	if (mlx)
		free_mlx(mlx);
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(1);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

char	*copy_line(char *line, int width)
{
	char	*copy;
	int		i;

	copy = (char *)malloc(sizeof(char) * (width + 1));
	if (!copy)
		return (0);
	i = -1;
	while (line[++i] != '\n')
		copy[i] = line[i];
	while (i < width)
		copy[i++] = ' ';
	copy[width] = ' ';
	return (copy);
}

int	check_valid_map(t_map *map)
{
	int	row;
	int	col;

	row = -1;
	while (++row < map->map_height)
	{
		col = -1;
		while (++col < map->map_width)
		{
			if (map->map[row][col] == ' ')
			{
				if (row - 1 >= 0 && map->map[row - 1][col] == '0')
					return (1);
				if (row + 1 < map->map_height && map->map[row + 1][col] == '0')
					return (1);
				if (col - 1 >= 0 && map->map[row][col - 1] == '0')
					return (1);
				if (col + 1 < map->map_width && map->map[row][col + 1] == '0')
					return (1);
			}
		}
	}
	return (0);
}

void	free_mlx(t_mlx *mlx)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (mlx->map.texture[i].img)
			mlx_destroy_image(mlx->ptr, mlx->map.texture[i].img);
	mlx_destroy_image(mlx->ptr, mlx->img.img);
	mlx_destroy_window(mlx->ptr, mlx->win);
	i = -1;
	while (mlx->map.map && ++i < mlx->map.map_height && mlx->map.map[i])
		free(mlx->map.map[i]);
	if (mlx->map.map)
		free(mlx->map.map);
}
