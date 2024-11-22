/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongchanhyeong <hongchanhyeong@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:33:41 by hongchanhye       #+#    #+#             */
/*   Updated: 2024/11/22 16:37:08 by hongchanhye      ###   ########.fr       */
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

t_coor	scalar_mult(t_coor vec, double scalar)
{
	vec.x *= scalar;
	vec.y *= scalar;
	return (vec);
}
