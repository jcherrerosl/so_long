# Variables principales
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directorios
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include
LIBFT_DIR = libft
MLX_DIR = minilibx-linux
ASSETS_DIR = assets/img

# Inclusiones y librerías
INCLUDE = -I$(INCLUDE_DIR) -I$(LIBFT_DIR)
MLX_LIB = -L$(MLX_DIR) -lmlx
LIBFT_LIB = -L$(LIBFT_DIR) -lft
X11_LIB = -lXext -lX11 -lm
LIBS = $(MLX_LIB) $(LIBFT_LIB) -L$(LIBFT_DIR)/ft_printf -lftprintf $(X11_LIB)

# Archivos fuente y objetos
SRCS = $(SRC_DIR)/so_long.c \
       $(SRC_DIR)/move_player.c \
       $(SRC_DIR)/load_map.c \
       $(SRC_DIR)/count_elements.c \
       $(SRC_DIR)/check_map.c \
       $(SRC_DIR)/check_path.c \
       $(SRC_DIR)/load_images.c \
       $(SRC_DIR)/draw_map.c \
       $(SRC_DIR)/start_game.c \
       $(SRC_DIR)/enemies.c \
       $(SRC_DIR)/check_utils.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Reglas principales
$(NAME): $(OBJS) libft/libft.a libft/ft_printf/libftprintf.a minilibx-linux/libmlx.a
	@echo "Building the executable $(NAME)..."
	$(CC) $(OBJS) -o $(NAME) $(LIBS) -pie
	@echo "Executable $(NAME) successfully created!"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE_DIR)/so_long.h
	@mkdir -p $(BUILD_DIR)
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

libft/libft.a:
	@echo "Building libft library..."
	$(MAKE) -C $(LIBFT_DIR)

libft/ft_printf/libftprintf.a:
	@echo "Building libftprintf library..."
	$(MAKE) -C $(LIBFT_DIR)/ft_printf

minilibx-linux/libmlx.a:
	@echo "Building MiniLibX library..."
	$(MAKE) -C $(MLX_DIR)

# Reglas de limpieza
clean:
	@echo "Cleaning object files and build directory..."
	rm -rf $(BUILD_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(LIBFT_DIR)/ft_printf clean
	$(MAKE) -C $(MLX_DIR) clean
	@echo "Clean completed!"

fclean: clean
	@echo "Cleaning executable and libraries..."
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR)/ft_printf fclean
	@echo "Full clean completed!"

re: fclean $(NAME)

# Desactivar sufijos implícitos
.SUFFIXES:
