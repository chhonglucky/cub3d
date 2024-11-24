/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:16:05 by jae-kang          #+#    #+#             */
/*   Updated: 2024/11/24 12:00:45 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_mlx	mlx;

	if (argc != 2)
		print_error("ERROR: wrong arguments", 0);
	if (init_mlx(&mlx) == 0)
		print_error("ERROR: init mlx", 0);
	parsing(argv[1], &mlx);
	mlx_loop_hook(mlx.ptr, rendering, &mlx);
	mlx_hook(mlx.win, 17, 1L << 0, close_window, &mlx);
	mlx_hook(mlx.win, 2, 1L << 0, key_press_callback, &mlx);
	mlx_hook(mlx.win, 3, 1L << 0, key_release_callback, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
