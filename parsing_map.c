/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:51:35 by kangjaehyun       #+#    #+#             */
/*   Updated: 2024/11/12 14:01:14 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void     count_map_size(int fd, t_map *map, t_mlx *mlx);
static void     get_point(int fd, t_mlx *mlx);
static char     *skip_info(int fd);
static int      line_digit_check(char *line);
static void     is_valid_map(t_mlx *mlx, char **map);

void    parsing_map(char *file_name, int fd, t_mlx *mlx)
{
    count_map_size(fd, &(mlx->map), mlx);
    printf("map size: %d x %d\n", mlx->map.map_width, mlx->map.map_height);
    fd = open(file_name, O_RDONLY);
    if (fd < 0)
        print_error("ERROR: cannot open .cub file", mlx);
    get_point(fd, mlx);
    is_valid_map(mlx, mlx->map.map);
}

static void    count_map_size(int fd, t_map *map, t_mlx *mlx)
{
    char    *line;

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
        if (line_digit_check(line))
        {
            free(line);
            print_error("ERROR: Wrong character in the map", mlx);
        }
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
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

static int line_digit_check(char *line)
{
    int i;

    i = 0;

    while (line[i] && line[i] != '\n')
    {
        if (!(line[i] >= '0' && line[i] <= '2') && line[i] != ' ')
            return (1);
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