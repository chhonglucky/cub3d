/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:41:01 by jae-kang          #+#    #+#             */
/*   Updated: 2024/11/23 17:51:28 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_texture(char *str)
{
	if (ft_strncmp(str, "NO", 3) == 0)
		return (0);
	else if (ft_strncmp(str, "SO", 3) == 0)
		return (0);
	else if (ft_strncmp(str, "WE", 3) == 0)
		return (0);
	else if (ft_strncmp(str, "EA", 3) == 0)
		return (0);
	return (1);
}

void	parsing_texture(char **split, t_mlx *mlx)
{
	t_texture_img	*data;

	if (split[1] == 0 || split[2])
		print_error("ERROR: texture is wrong", mlx);
	data = (t_texture_img *)get_mem(split[0], mlx); // map의 t_texture_img[위치]를 리턴
	if (!data || data->img)
		print_error("ERROR", mlx);
	data->img = mlx_xpm_file_to_image(mlx->ptr, split[1], &data->tex_w, &data->tex_h);
	if (data->img == 0)
		print_error("ERROR: mlx_xpm_file_to_image()", mlx);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line, &data->endian);
	if (data->addr == 0)
		print_error("ERROR: error in mlx_get_data_addr()", mlx);
}
