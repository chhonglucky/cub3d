/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:11:09 by chanhhon          #+#    #+#             */
/*   Updated: 2024/11/18 12:18:36 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_mlx *mlx, int x, int y, char dir)
{
	int	i;

	mlx->player.pos.x = x + 0.5;
	mlx->player.pos.y = y + 0.5;
	mlx->player.dir_vec.x = 0;
	mlx->player.dir_vec.y = 0;
	if (dir == 'S')
		mlx->player.dir_vec.y += 1;
	else if (dir == 'N')
		mlx->player.dir_vec.y -= 1;
	else if (dir == 'E')
		mlx->player.dir_vec.x -= 1;
	else
		mlx->player.dir_vec.x += 1;
	mlx->player.cam_vec.x = mlx->player.dir_vec.y * FOV;
	mlx->player.cam_vec.y = -mlx->player.dir_vec.x * FOV;
	i = -1;
	while (++i < 6)
		mlx->player.key_map[i] = 0;
}
