/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:11:09 by chanhhon          #+#    #+#             */
/*   Updated: 2024/11/24 11:12:04 by chanhhon         ###   ########.fr       */
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

void	rotate_player(t_mlx *mlx)
{
	if (mlx->player.key_map[4] == mlx->player.key_map[5])
		return ;
	if (mlx->player.key_map[5] == 1)
	{
		mlx->player.dir_vec = rotate(mlx->player.dir_vec, -ROTSPEED);
		mlx->player.cam_vec = rotate(mlx->player.cam_vec, -ROTSPEED);
	}
	else if (mlx->player.key_map[4] == 1)
	{
		mlx->player.dir_vec = rotate(mlx->player.dir_vec, ROTSPEED);
		mlx->player.cam_vec = rotate(mlx->player.cam_vec, ROTSPEED);
	}
}

void	move_player(t_mlx *mlx)
{
	t_coor	delta;
	t_coor	player;

	if (mlx->player.key_map[0] == mlx->player.key_map[2]
		&& mlx->player.key_map[1] == mlx->player.key_map[3])
		return ;
	delta = move_decision(&(mlx->player));
	player = mlx->player.pos;
	if (is_movable(mlx, sum_vec(player, mult_scal(delta, MOVESPEED)), delta))
		player = sum_vec(player, mult_scal(delta, MOVESPEED));
	mlx->player.pos = player;
}
