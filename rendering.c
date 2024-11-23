/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:36:59 by hongchanhye       #+#    #+#             */
/*   Updated: 2024/11/23 14:23:44 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	object_detect(t_draw *arg, t_mlx *mlx)
{
	int	side;

	while (mlx->map.map[arg->map.y][arg->map.x] == '0')
	{
		if (arg->s_dist.x < arg->s_dist.y)
		{
			arg->s_dist.x += arg->d_dist.x;
			arg->map.x += arg->step.x;
			side = 0;
		}
		else
		{
			arg->s_dist.y += arg->d_dist.y;
			arg->map.y += arg->step.y;
			side = 1;
		}
	}
	return (side);
}

static int	check_side(t_draw *arg, t_mlx *mlx, int side)
{
	int		tex_num;
	double	perp_wall_dist;

	if (side == 0)
	{
		perp_wall_dist = arg->s_dist.x - arg->d_dist.x;
		arg->wall_x = mlx->player.pos.y + perp_wall_dist * arg->ray_dir.y;
		if (arg->ray_dir.x > 0)
			tex_num = 0;
		else
			tex_num = 1;
	}
	else
	{
		perp_wall_dist = arg->s_dist.y - arg->d_dist.y;
		arg->wall_x = mlx->player.pos.x + perp_wall_dist * arg->ray_dir.x;
		if (arg->ray_dir.y > 0)
			tex_num = 2;
		else
			tex_num = 3;
	}
	arg->wall_x -= floor(arg->wall_x);
	arg->line_height = (int)(HEIGHT / perp_wall_dist);
	return (tex_num);
}

static void	set_point(t_draw *arg)
{
	arg->draw_start = -arg->line_height / 2 + HEIGHT / 2;
	if (arg->draw_start < 0)
		arg->draw_start = 0;
	arg->draw_end = arg->line_height / 2 + HEIGHT / 2;
	if (arg->draw_end >= HEIGHT)
		arg->draw_end = HEIGHT - 1;
}

static void	put_point(t_draw *arg, t_mlx *mlx, int x, t_texture_img *tex)
{
	int		y;
	double	step;
	double	tex_pos;

	step = 1.0 * tex->tex_h / arg->line_height;
	tex_pos = (arg->draw_start - HEIGHT / 2 + arg->line_height / 2) * step;
	y = -1;
	while (++y < arg->draw_start - 1 && y < arg->draw_end)
		*(unsigned int *)(mlx->img.addr + y * (mlx->img.line) \
			+ x * (mlx->img.bpp / 8)) = mlx->map.ceilling;
	while (++y < arg->draw_end)
	{
		arg->tex.y = (int)tex_pos;
		tex_pos += step;
		*(unsigned int *)(mlx->img.addr + y * (mlx->img.line) \
			+ x * (mlx->img.bpp / 8)) \
			= *(unsigned int *)(tex->addr + tex->line * arg->tex.y \
			+ arg->tex.x * (tex->bpp / 8));
	}
	while (++y < HEIGHT)
		*(unsigned int *)(mlx->img.addr + y * (mlx->img.line) \
			+ x * (mlx->img.bpp / 8)) = mlx->map.floor;
}

int rendering(t_mlx *mlx)
{
	int		x;
	int 	side;
	int		tex_num;
	t_draw	arg;

	move_player(mlx);
	rotate_player(mlx);
	x = 0;
	while (x < WIDTH)
	{
		init_draw_args(&arg, mlx, x);
		side = object_detect(&arg, mlx);
		tex_num = check_side(&arg, mlx, side);
		set_point(&arg);
		arg.tex.x = (int)(arg.wall_x * mlx->map.texture[tex_num].tex_w);
		if ((side == 0 && arg.ray_dir.x > 0)
				|| (side == 1 && arg.ray_dir.y < 0))
			arg.tex.x = mlx->map.texture[tex_num].tex_w - arg.tex.x - 1;
		put_point(&arg, mlx, x, &(mlx->map.texture[tex_num]));
		x++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.img, 0, 0);
	return (0);
}