/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:04:49 by kangjaehyun       #+#    #+#             */
/*   Updated: 2024/11/23 15:26:17 by chanhhon         ###   ########.fr       */
/*                                                                            */
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

void    last_enter(char *file_name, t_mlx *mlx)
{
    int     fd;
    char    *a;
    char    *b;
    
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

static void	set_direction(t_mlx *mlx, int i, int j)
{
	if (mlx->map.map[i][j] == 'N')
	{
		mlx->player.dir_vec.x = 0;
		mlx->player.dir_vec.y = 1;
	}
	if (mlx->map.map[i][j] == 'S')
	{
		mlx->player.dir_vec.x = 0;
		mlx->player.dir_vec.y = -1;
	}
	if (mlx->map.map[i][j] == 'E')
	{
		mlx->player.dir_vec.x = 1;
		mlx->player.dir_vec.y = 0;
	}
	if (mlx->map.map[i][j] == 'W')
	{
		mlx->player.dir_vec.x = -1;
		mlx->player.dir_vec.y = 0;
	}
}

void	set_position(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->map.map_height)
	{
		j = 0;
		while (j < mlx->map.map_width)
		{
			if (mlx->map.map[i][j] != '0' && mlx->map.map[i][j] != '1')
			{
				set_direction(mlx, i, j);
				mlx->map.map[i][j] = '0';
				mlx->player.pos.y = i + 0.5;
				mlx->player.pos.x = j + 0.5;
			}
			j++;
		}
		i++;
	}
}
