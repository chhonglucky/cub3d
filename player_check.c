/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:04:58 by chanhhon          #+#    #+#             */
/*   Updated: 2024/11/23 16:29:48 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_map(t_mlx *mlx, t_coor ang)
{
	if (ang.x < 0 || ang.x >= mlx->map.map_width)
		return (1);
	else if (ang.y < 0 || ang.y >= mlx->map.map_height)
		return (1);
	else if (mlx->map.map[(int)ang.y][(int)ang.x] != '0')
		return (1);
	return (0);
}

int	is_movable(t_mlx *mlx, t_coor player, t_coor delta)
{
	int		i;
	t_coor	check_ang;

	i = 0;
	while (i < 360)
	{
		check_ang = sum_vec(player, mult_scal(rotate(delta, i), PLAYER_SIZE));
		if (check_map(mlx, check_ang))
			return (0);
		i += 90;
	}
	return (1);
}

t_coor	move_decision(t_pov *player)
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
