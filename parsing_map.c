/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:51:35 by kangjaehyun       #+#    #+#             */
/*   Updated: 2024/11/23 15:02:42 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		count_map_size(int fd, t_map *map, t_mlx *mlx);
static void     get_point(int fd, t_mlx *mlx);
static char     *skip_info(int fd);
static int      line_digit_check(char *line, int *n);
static void     is_valid_map(t_mlx *mlx, char **map);

void    parsing_map(char *file_name, int fd, t_mlx *mlx)
{
	if (count_map_size(fd, &(mlx->map), mlx) != 1)
		print_error("ERROR: where is my point?", mlx);
    printf("map size: %d x %d\n", mlx->map.map_width, mlx->map.map_height);
    fd = open(file_name, O_RDONLY);
    if (fd < 0)
        print_error("ERROR: cannot open .cub file", mlx);
    get_point(fd, mlx);
    is_valid_map(mlx, mlx->map.map);
	set_position(mlx);
}

static int    count_map_size(int fd, t_map *map, t_mlx *mlx)
{
    char    *line;
	int		n;

	n = 0;
    line = get_next_line(fd);
    while (line && line[0] == '\n')
    {
        free(line);
        line = get_next_line(fd);
    }
    while (line)
    {
        if (map->map_width < (int)ft_strlen(line) - 1)
            map->map_width = (int)ft_strlen(line) - 1;
        map->map_height += 1;
        if (line_digit_check(line, &n))
        {
            free(line);
            print_error("ERROR: Wrong character in the map", mlx);
        }
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
	return (n);
}

static void    get_point(int fd, t_mlx *mlx)
{
    char    *line;
    int     i;

    mlx->map.map = (char **)malloc(sizeof(char *) * mlx->map.map_height);
    if (mlx->map.map == 0)
        print_error("ERROR: malloc error", mlx);
    i = 0;
    line = skip_info(fd);
    while (line)
    {
        mlx->map.map[i] = copy_line(line, mlx->map.map_width);
        if (mlx->map.map[i++] == 0)
            print_error("ERROR: malloc error", mlx);
        free(line);
        line = get_next_line(fd);
    }
}

static char    *skip_info(int fd)
{
    char    *line;

    line = get_next_line(fd);
    while (line)
    {
        if ((line[0] >= '0' && line[0] <= '2') || line[0] == ' ')
            break ;
        free(line);
        line = get_next_line(fd);
    }
    return (line);
}

static int line_digit_check(char *line, int *n)
{
    int i;
	
    i = 0;
    while (line[i] && line[i] != '\n')
    {
        if (!(line[i] >= '0' && line[i] <= '2') && line[i] != ' ')
			if (line[i] != 'N' && line[i] != 'S' && line[i] != 'E' && line[i] != 'W')
				return (1);
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
			*n += 1;
        i++;
    }
    return (0);
}

void    is_valid_map(t_mlx *mlx, char **map)
{
    int i;
    int j;

    i = -1;
    while (++i < mlx->map.map_height)
    {
        j = 0;
        if (i == 0 || i == mlx->map.map_height - 1)
        {
            while (j < mlx->map.map_width)
                if (map[i][j++] != '1')
                    print_error("ERROR: there is no wall", mlx);
        }
        else
            if (map[i][0] != '1' || map[i][mlx->map.map_width - 1] != '1')
                print_error("ERROR: there is no wall", mlx);
    }
}
