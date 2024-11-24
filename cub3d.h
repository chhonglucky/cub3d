/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:10:33 by jae-kang          #+#    #+#             */
/*   Updated: 2024/11/24 11:29:42 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include "./gnl/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# define WIDTH	1280
# define HEIGHT	720
# define FOV 0.66
# define PLAYER_SIZE 0.125
# define ROTSPEED 1
# define MOVESPEED 0.03125

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124

typedef struct s_double_coordinate
{
	double	x;
	double	y;
}	t_coor;

typedef struct s_int_coordinate
{
	int	x;
	int	y;
}	t_int_coor;

typedef struct s_pov
{
	t_coor	pos;
	t_coor	dir_vec;
	t_coor	cam_vec;
	int		key_map[6];
}	t_pov;

typedef struct s_texture_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line;
	int		endian;
	int		tex_w;
	int		tex_h;
}	t_texture_img;

typedef struct s_map
{
	t_texture_img	texture[4];
	char			**map;
	int				map_width;
	int				map_height;
	unsigned int	floor;
	unsigned int	ceilling;
}	t_map;

typedef struct s_mlx
{
	void			*ptr;
	void			*win;
	t_texture_img	img;
	t_pov			player;
	t_map			map;
}	t_mlx;

typedef struct s_draw
{
	t_coor		ray_dir;
	t_coor		s_dist;
	t_coor		d_dist;
	t_int_coor	map;
	t_int_coor	step;
	t_int_coor	tex;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		wall_x;
}	t_draw;

void	parsing(char *file_name, t_mlx *mlx);
int		parsing_info(int fd, t_mlx *mlx);

int		init_mlx(t_mlx *mlx);
void	init_map(t_map *map);

void	parsing_map(char *file_name, int fd, t_mlx *mlx);

int		is_texture(char *str);
void	parsing_texture(char **split, t_mlx *mlx);

int		is_color(char *str);
void	parsing_color(char **split, t_mlx *mlx);

int		check_file_name(char *file_name);
void	*get_mem(char *str, t_mlx *mlx);
void	last_enter(char *file_name, t_mlx *mlx);
void	set_position(t_mlx *mlx);

void	print_error(char *msg, t_mlx *mlx);
void	free_split(char **str);
char	*copy_line(char *line, int width);
void	free_mlx(t_mlx *mlx);
int		check_valid_map(t_map *map);

int		key_press_callback(int keycode, t_mlx *mlx);
int		key_release_callback(int keycode, t_mlx *mlx);

void	init_draw_args(t_draw *arg, t_mlx *mlx, int x);

void	init_player(t_mlx *mlx, int x, int y, char dir);
void	rotate_player(t_mlx *mlx);
void	move_player(t_mlx *mlx);

int		check_map(t_mlx *mlx, t_coor ang);
int		is_movable(t_mlx *mlx, t_coor player, t_coor delta);
t_coor	move_decision(t_pov *player);

t_coor	rotate(t_coor before, int deg);
t_coor	mult_scal(t_coor vec, double scalar);
t_coor	sum_vec(t_coor vec1, t_coor vec2);

int		rendering(t_mlx *mlx);

int		close_window(t_mlx *mlx);
void	free_map(t_mlx *mlx);

#endif