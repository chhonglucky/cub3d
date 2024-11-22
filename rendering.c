/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongchanhyeong <hongchanhyeong@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:36:59 by hongchanhye       #+#    #+#             */
/*   Updated: 2024/11/22 16:33:59 by hongchanhye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int rendering(t_mlx *mlx)
{
	int		x;
	int 	side;
	int		tex_num;
	t_draw	arg;

	move_player(mlx);
	rotate_player(mlx);

	
}