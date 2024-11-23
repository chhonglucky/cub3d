CC=cc
CFLAGS=-Wall -Wextra -Werror -fsanitize=address -g
LIBDIR=libft
LIBFT_NAME=libft.a
LIBFT=-L$(LIBDIR) -lft
MLXDIR=mlx
MLX_NAME=libmlx.a
LDFLAGS=-L. -lft -lmlx -framework OpenGL -framework AppKit
SRCS=gnl/get_next_line.c gnl/get_next_line_utils.c \
	main.c init.c parsing.c parsing_color.c parsing_texture.c parsing_map.c \
	parsing_utils.c utils.c \
	close_window.c hook_callback.c player_check.c player.c rendering.c \
	util_math.c init_data.c

OBJS=$(SRCS:.c=.o)
NAME=CUB3D

all: $(NAME)

$(NAME) : $(MLX_NAME) $(LIBFT_NAME) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

$(LIBFT_NAME) :
	$(MAKE) -C $(LIBDIR)
	mv $(LIBDIR)/$(LIBFT_NAME) $(LIBFT_NAME)

$(MLX_NAME) :
	$(MAKE) -C $(MLXDIR)
	mv $(MLXDIR)/$(MLX_NAME) $(MLX_NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
	$(MAKE) -C $(LIBDIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(MLXDIR) clean
	$(MAKE) -C $(LIBDIR) fclean
	rm -rf $(MLX_NAME) $(LIBFT_NAME)

re: fclean all

.PHONY: all clean fclean re