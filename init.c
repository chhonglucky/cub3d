/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:31:09 by jae-kang          #+#    #+#             */
/*   Updated: 2024/11/12 16:21:13 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_mlx(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		return (0);
	mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, "cub3d");
	if (!mlx->win)
		return (0);
	mlx->img.img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	if (!mlx->img.img)
	{
		mlx_destroy_window(mlx->ptr, mlx->win);
		return (0);
	}
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bpp,
		&mlx->img.line, &mlx->img.endian);
	if (!mlx->img.addr)
	{
		mlx_destroy_image(mlx->ptr, mlx->img.img);
		mlx_destroy_window(mlx->ptr, mlx->win);
		return (0);
	}
	return (1);
}

void	init_map(t_map *map)
{
	map->map = 0;
	map->map_height = 0;
	map->map_width = 0;
	map->floor = UINT32_MAX;
	map->ceilling = UINT32_MAX;
	map->texture[0].img = 0;
	map->texture[0].addr = 0;
	map->texture[1].img = 0;
	map->texture[1].addr = 0;
	map->texture[2].img = 0;
	map->texture[2].addr = 0;
	map->texture[3].img = 0;
	map->texture[3].addr = 0;
}

void	init_player(t_mlx *mlx, int x, int y, char dir)
{

}
