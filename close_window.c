/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:14:56 by chanhhon          #+#    #+#             */
/*   Updated: 2024/11/23 11:19:17 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_mlx *mlx)
{
	free_map(mlx);
	exit(0);
	return (0);
}

void	free_map(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (mlx->map.texture[i].img)
			mlx_destroy_image(mlx->ptr, mlx->map.texture[i].img);
		i++;
	}
	mlx_destroy_image(mlx->ptr, mlx->img.img);
	mlx_destroy_window(mlx->ptr, mlx->win);
	i = 0;
	while (i < mlx->map.map_height)
	{
		free(mlx->map.map[i]);
		i++;
	}
	if (mlx->map.map)
		free(mlx->map.map);
}
