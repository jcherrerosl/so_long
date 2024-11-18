NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

SRCS = check_map.c check_path.c count_elements.c load_map.c so_long.c \
		draw_map.c move_player.c start_game.c load_images.c \


OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = libft/ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a


LIBS = -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -lXext -lX11 -lm


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

$(MLX):
	make -C $(MLX_DIR)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(FT_PRINTF_DIR)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(FT_PRINTF_DIR)
	make fclean -C $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re
