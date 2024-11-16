# Nombre del ejecutable
NAME = so_long

# Compilador y flags
CC = gcc
CFLAGS = -fsanitize=address -g3

# Archivos fuente
SRCS = check_map.c  check_path.c  count_elements.c  load_map.c  so_long.c \
		draw_map.c move_player.c  \

# Archivos objeto
OBJS = $(SRCS:.c=.o)

# Directorios de librerías
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx
MLX = $(MLX_DIR)/libmlx.a

# Librerías necesarias
LIBS = -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft -lXext -lX11 -lm

# Reglas principales
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

# Reglas para libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Reglas para MiniLibX
$(MLX):
	make -C $(MLX_DIR)

# Limpieza
clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(MLX_DIR)

re: fclean all

# Marcadores de phony para evitar conflictos con archivos
.PHONY: all clean fclean re
