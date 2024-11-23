/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:16:05 by jae-kang          #+#    #+#             */
/*   Updated: 2024/11/23 17:49:51 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	leak()
// {
// 	system("leaks CUB3D");
// }

int	main(int argc, char *argv[])
{
	t_mlx	mlx;

	// atexit(leak);
	if (argc != 2)
		print_error("ERROR: wrong arguments", 0);
	if (init_mlx(&mlx) == 0)
		print_error("ERROR: init mlx", 0);
	parsing(argv[1], &mlx);
	// print_parsing(&mlx, &mlx.map); // 파싱 전체 출력

	mlx_loop_hook(mlx.ptr, rendering, &mlx);
	mlx_hook(mlx.win, 17, 1L << 0, close_window, &mlx);
	mlx_hook(mlx.win, 2, 1L << 0, key_press_callback, &mlx);
	mlx_hook(mlx.win, 3, 1L << 0, key_release_callback, &mlx);
	mlx_loop(mlx.ptr);

	return (0);
}
