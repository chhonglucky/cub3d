/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:16:05 by jae-kang          #+#    #+#             */
/*   Updated: 2024/11/12 09:44:47 by jae-kang         ###   ########.fr       */
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
	return (0);
}
