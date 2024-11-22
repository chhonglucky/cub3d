/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongchanhyeong <hongchanhyeong@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:11:09 by chanhhon          #+#    #+#             */
/*   Updated: 2024/11/22 16:49:39 by hongchanhye      ###   ########.fr       */
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

static t_coor	move_decision(t_pov *player)
{
	t_coor	direction;

	if (player->key_map[0] == 1 && player->key_map[2] == 0)
	{
		if (player->key_map[1] == 1 && player->key_map[3] == 0)
			direction = rotate(player->dir_vec, 45);
		else if (player->key_map[1] == 0 && player->key_map[3] == 1)
			direction = rotate(player->dir_vec, 315);
		else
			direction = player->dir_vec;
	}
	else if (player->key_map[0] == 0 && player->key_map[2] == 1)
	{
		if (player->key_map[1] == 1 && player->key_map[3] == 0)
			direction = rotate(player->dir_vec, 135);
		else if (player->key_map[1] == 0 && player->key_map[3] == 1)
			direction = rotate(player->dir_vec, 225);
		else
			direction  = rotate(player->dir_vec, 180);
	}
	else if (player->key_map[1] == 1)
		direction = rotate(player->dir_vec, 90);
	else
		direction = rotate(player->dir_vec, 270);
	return (direction);
}

static int check_map(t_mlx *mlx, t_coor ang)
{
	if (ang.x < 0 || ang.x >= mlx->map.map_width)
		return (1);
	else if (ang.y < 0 || ang.y >= mlx->map.map_height)
		return (1);
	else if (mlx->map.map[(int)ang.y][(int)ang.x] != '0')
		return (1);
	return (0);
}

static int	is_movable(t_mlx *mlx, t_coor player, t_coor delta)
{
	t_coor	ang
}




