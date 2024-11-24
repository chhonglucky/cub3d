/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   parsing_utils.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kangjaehyun <kangjaehyun@student.42.fr>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/11 16:04:49 by kangjaehyun	   #+#	#+#			 */
/*   Updated: 2024/11/23 23:26:13 by kangjaehyun	  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "./cub3d.h"

int	check_file_name(char *file_name)
{
	char	*temp;

	temp = ft_strrchr(file_name, '.');
	if (!temp)
		return (1);
	if (ft_strncmp(temp, ".cub", 5) != 0)
		return (1);
	return (0);
}

void	*get_mem(char *str, t_mlx *mlx)
{
	if (ft_strncmp(str, "WE", 3) == 0)
		return (&mlx->map.texture[0]);
	else if (ft_strncmp(str, "EA", 3) == 0)
		return (&mlx->map.texture[1]);
	else if (ft_strncmp(str, "SO", 3) == 0)
		return (&mlx->map.texture[2]);
	else if (ft_strncmp(str, "NO", 3) == 0)
		return (&mlx->map.texture[3]);
	else if (ft_strncmp(str, "F", 2) == 0)
		return (&mlx->map.floor);
	else if (ft_strncmp(str, "C", 2) == 0)
		return (&mlx->map.ceilling);
	else
		return (0);
}

void	last_enter(char *file_name, t_mlx *mlx)
{
	int		fd;
	char	*a;
	char	*b;

	fd = open(file_name, O_RDWR);
	if (fd < 0)
		print_error("ERROR: cannot open .cub file", mlx);
	a = get_next_line(fd);
	if (a == 0)
		print_error("ERROR: map is empty", mlx);
	while (a)
	{
		b = get_next_line(fd);
		if (b == 0)
		{
			if (a[ft_strlen(a) - 1] != '\n')
				ft_putchar_fd('\n', fd);
			free(a);
			close(fd);
			return ;
		}
		free(a);
		a = b;
	}
}

void	set_position(t_mlx *mlx)
{
	int	i;
	int	j;

	i = -1;
	while (++i < mlx->map.map_height)
	{
		j = -1;
		while (++j < mlx->map.map_width)
		{
			if (mlx->map.map[i][j] != '0' && mlx->map.map[i][j] != '1'
				&& mlx->map.map[i][j] != ' ')
			{
				init_player(mlx, j, i, mlx->map.map[i][j]);
				mlx->map.map[i][j] = '0';
			}
		}
	}
}
