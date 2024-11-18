/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:16:41 by jae-kang          #+#    #+#             */
/*   Updated: 2024/11/12 10:01:30 by jae-kang         ###   ########.fr       */
/*                                                                            */
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

char    *copy_line(char *line, int width)
{
    char    *copy;
    int     i;

    copy = (char *)malloc(sizeof(char) * (width + 1));
    if (!copy)
        return (0);
    i = -1;
    while (line[++i] != '\n')
    {
		copy[i] = line[i];
		if (copy[i] == ' ')
			copy[i] = '1';
	}
    while (i < width)
        copy[i++] = '1';
	copy[width] = 0;
    return copy;
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
	while (mlx->map.map && ++i < mlx->map.map_height)
		free(mlx->map.map[i]);
	if (mlx->map.map)
		free(mlx->map.map);
}

void	print_parsing(t_map *map)
{
	printf("천장: %x\n", map->ceilling);
	printf("바닥: %x\n", map->floor);
	for (int i = 0; i < 4; i++)
	{
		printf("texture[%d]: ", i);
		if (map->texture[i].addr)
			printf("OK");
		printf("\n");
	}
	printf("------------------------------------------------\n");
	for (int i = 0; i < map->map_height; i++)
		printf("%s\n", map->map[i]);
	printf("------------------------------------------------\n");
}