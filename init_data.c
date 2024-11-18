/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:32:50 by chanhhon          #+#    #+#             */
/*   Updated: 2024/11/18 11:09:39 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_delta_dist(t_draw *arg)
{
	if (arg->ray_dir.x == 0)
		arg->d_dist.x = 1e30;
	else
		arg->d_dist.x = fabs(1 / arg->ray_dir.x);
	if (arg->ray_dir.y == 0)
		arg->d_dist.y = 1e30;
	else
		arg->d_dist.y = fabs(1 / arg->ray_dir.y);
}

static void init_side_dist(t_draw *arg, t_mlx *mlx)
{
	if (arg->ray_dir.x < 0)
	{
		arg->step.x = -1;
		arg->s_dist.x = (mlx->player.pos.x - arg->map.x) * arg->d_dist.x;
	}
	else
	{
		arg->step.x = 1;
		arg->s_dist.x = (arg->map.x + 1 - mlx->player.pos.x) * arg->d_dist.x;
	}
	if (arg->ray_dir.y < 0)
	{
		arg->step.y = -1;
		arg->s_dist.y = (mlx->player.pos.y - arg->map.y) * arg->d_dist.y;
	}
	else
	{
		arg->step.y = 1;
		arg->s_dist.y = (arg->map.y + 1 - mlx->player.pos.y) * arg->d_dist.y;
	}
}

static void	init_ray_dir(t_draw *arg, t_mlx *mlx, double cam_pos)
{
	arg->ray_dir.x = mlx->player.dir_vec.x + mlx->player.cam_vec.x + cam_pos;
	arg->ray_dir.y = mlx->player.dir_vec.y + mlx->player.cam_vec.y + cam_pos;
}

static void	init_map_coordinate(t_draw *arg, t_mlx *mlx)
{
	arg->map.x = (int)mlx->player.pos.x;
	arg->map.y = (int)mlx->player.pos.y;
}

void	init_draw_args(t_draw *arg, t_mlx *mlx, int x)
{
	double width_position;

	width_position = 2.0 * x / WIDTH - 1;
	init_ray_dir(arg, mlx, width_position);
	init_map_coordinate(arg, mlx);
	init_delta_dist(arg);
	init_side_dist(arg, mlx);
}
