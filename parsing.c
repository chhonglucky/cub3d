/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:40:19 by jae-kang          #+#    #+#             */
/*   Updated: 2024/11/12 09:59:57 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_parsing_info(t_map *map);
static int	do_par(char **split, t_mlx *mlx, char *line);

void	parsing(char *file_name, t_mlx *mlx)
{
	int	fd;

	init_map(&(mlx->map));
	if (check_file_name(file_name))
		print_error("ERROR: file name is wrong", mlx);
	last_enter(file_name, mlx);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		print_error("ERROR: cannot open .cub file", mlx);
	if (parsing_info(fd, mlx))
		return ;
	parsing_map(file_name, fd, mlx);
	print_parsing(&mlx->map);
	close(fd);
}

int	parsing_info(int fd, t_mlx *mlx)
{
	char	*line;
	char	**split;

	line = get_next_line(fd);
	while (line)
	{
		if (line == 0)
			return (1);
		line = ft_strip(line);
		if (line == 0)
		{
			line = get_next_line(fd);
			continue;
		}
		split = ft_split(line, ' ');
		if (!split)
			return (1);
		if (do_par(split, mlx, line) == 1)
			print_error("ERROR: map is wrong (parsing_info)", mlx);
		if (check_parsing_info(&mlx->map) == 0)
			return (0);
		line = get_next_line(fd);
	}
	print_error("ERROR: map is wrong (parsing_info)", mlx);
	return (1);
}

static int	do_par(char **split, t_mlx *mlx, char *line)
{
	if (is_texture(split[0]) == 0)
		parsing_texture(split, mlx);
	else if (is_color(split[0]) == 0)
		parsing_color(split, mlx);
	else if (split[0])
	{
		free(line);
		free_split(split);
		return (1);
	}
	free(line);
	free_split(split);
	return (0);
}

static int	check_parsing_info(t_map *map)
{	
	if (map->ceilling != UINT32_MAX && map->floor != UINT32_MAX)
		if (map->texture[0].addr && map->texture[1].addr \
			&& map->texture[2].addr && map->texture[3].addr)
				return (0);
	return (1);
}
