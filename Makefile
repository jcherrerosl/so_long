NAME = so_long

SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include
LIBFT_DIR = libft
MLX_DIR = minilibx-linux
ASSETS_DIR = assets/img

INCLUDE = -I$(INCLUDE_DIR) -I$(LIBFT_DIR)

SRCS = $(SRC_DIR)/so_long.c \
       $(SRC_DIR)/move_player.c \
       $(SRC_DIR)/load_map.c \
       $(SRC_DIR)/count_elements.c \
       $(SRC_DIR)/check_map.c \
       $(SRC_DIR)/check_path.c \
       $(SRC_DIR)/load_images.c \
       $(SRC_DIR)/draw_map.c \
       $(SRC_DIR)/start_game.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

MLX_LIB = -L$(MLX_DIR) -lmlx
LIBFT_LIB = -L$(LIBFT_DIR) -lft
X11_LIB = -lXext -lX11 -lm

# Add the following line to disable implicit rules that might create .o files in src
.SUFFIXES:

$(NAME): libft/libft.a libft/ft_printf/libftprintf.a minilibx-linux/libmlx.a $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(MLX_LIB) $(LIBFT_LIB) -Llibft/ft_printf -lftprintf $(X11_LIB)

libft/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

libft/ft_printf/libftprintf.a:
	$(MAKE) -C $(LIBFT_DIR)/ft_printf

minilibx-linux/libmlx.a:
	$(MAKE) -C $(MLX_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
