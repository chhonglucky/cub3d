/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:33:41 by hongchanhye       #+#    #+#             */
/*   Updated: 2024/11/23 14:22:46 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_coor	rotate(t_coor before, int deg)
{
	t_coor	after;
	double	rad;

	rad = deg * M_PI / 180;
	after.x = cos(rad) * before.x - sin(rad) * before.y;
	after.y = sin(rad) * before.x + cos(rad) * before.y;
	return (after);
}

t_coor	mult_scal(t_coor vec, double scalar)
{
	vec.x *= scalar;
	vec.y *= scalar;
	return (vec);
}

t_coor	sum_vec(t_coor vec1, t_coor vec2)
{
	t_coor	return_vec;

	return_vec.x = vec1.x + vec2.x;
	return_vec.y = vec2.y + vec2.y;
	return (return_vec);
}
