/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_callback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:07:22 by chanhhon          #+#    #+#             */
/*   Updated: 2024/11/23 11:54:33 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press_callback(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
	{
		close_window(mlx);
		exit(0);
	}
	else if (keycode == KEY_W)
		mlx->player.key_map[0] = 1;
	else if (keycode == KEY_A)
		mlx->player.key_map[1] = 1;
	else if (keycode == KEY_S)
		mlx->player.key_map[2] = 1;
	else if (keycode == KEY_D)
		mlx->player.key_map[3] = 1;
	else if (keycode == KEY_LEFT)
		mlx->player.key_map[4] = 1;
	else if (keycode == KEY_RIGHT)
		mlx->player.key_map[5] = 1;
	return (0);
}

int	key_release_callback(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_W)
		mlx->player.key_map[0] = 0;
	else if (keycode == KEY_A)
		mlx->player.key_map[1] = 0;
	else if (keycode == KEY_S)
		mlx->player.key_map[2] = 0;
	else if (keycode == KEY_D)
		mlx->player.key_map[3] = 0;
	else if (keycode == KEY_LEFT)
		mlx->player.key_map[4] = 0;
	else if (keycode == KEY_RIGHT)
		mlx->player.key_map[5] = 0;
	return (0);
}