/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:52:48 by jae-kang          #+#    #+#             */
/*   Updated: 2024/11/24 10:39:12 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int			check_colors(char **split);
static unsigned int	ft_tohex(char **colors);

int	is_color(char *str)
{
	if (ft_strncmp(str, "F", 2) == 0)
		return (0);
	else if (ft_strncmp(str, "C", 2) == 0)
		return (0);
	else
		return (1);
}

void	parsing_color(char **split, t_mlx *mlx)
{
	char			**color;
	unsigned int	*data;

	if (split[1] == 0 || split[2])
		print_error("ERROR: parsing error (parsing_color)", mlx);
	data = (unsigned int *) get_mem(split[0], mlx);
	if (!data || *data != UINT32_MAX)
		print_error("ERROR: parsing error (parsing_color)", mlx);
	color = ft_split(split[1], ',');
	if (check_colors(color))
		*data = ft_tohex(color);
	free_split(color);
	if (*data == UINT32_MAX)
		print_error("ERROR: parsing error (parsing_color)", mlx);
}

static int	check_colors(char **split)
{
	int	i;
	int	j;

	i = 0;
	while (split[i])
	{
		j = -1;
		while (split[i][++j])
			if (ft_isdigit(split[i][j]) == 0)
				return (0);
		i++;
	}
	if (i != 3)
		return (0);
	return (1);
}

static unsigned int	ft_tohex(char **colors)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	result;

	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	if (r >= 256 || g >= 256 || b >= 256)
		return (UINT32_MAX);
	result = (0 << 24) | (r << 16) | (g << 8) | b;
	return (result);
}
