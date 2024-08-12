NAME = cub3D
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
LIBFTDIR = includes/libft/
LIBFT_OBJ = includes/libft/includes/obj
OBJ_DIR = obj/
SRC_DIR = srcs/
MLX_DIR = minilibx-linux/
MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11 -lm

SRC_1 = srcs/cub3d.c
SRC_2 = srcs/game/settings.c \
		srcs/parsing/parsing.c \
		srcs/parsing/verify_direction.c \
		srcs/parsing/verify_map.c \
		srcs/errors/errors.c \
		srcs/utils/parsing_utils.c \
		srcs/utils/function_utils.c
BONUS = srcs/parsing/parsing_map.c

OBJ_1 = $(patsubst %.c,$(OBJ_DIR)%.o,$(SRC_1))
OBJ_2 = $(patsubst %.c,$(OBJ_DIR)%.o,$(SRC_2))
BONUS_OBJ = $(patsubst %.c,$(OBJ_DIR)%.o,$(BONUS))

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) $(CFLAGS) -c $< -o $@

INCLUDE = -L $(LIBFTDIR) -lft
INCLUDES = -I/usr/include -Imlx

.c.o:
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ_1) $(OBJ_2) $(BONUS_OBJ)
	@echo "Compiling libft..."
	@make -C $(LIBFTDIR)
	@echo "Compiling $(NAME)..."
	@$(CC) $(FLAGS) $(OBJ_1) $(OBJ_2) $(BONUS_OBJ) -o $(NAME) $(INCLUDE) $(INCLUDES) $(MLX_FLAGS)
	@echo "$(NAME) compiled successfully."

$(MLX_LIB):
	@echo "Compiling mlx..."
	@make -C $(MLX_DIR)
	@echo "mlx compiled successfully."

all: $(MLX_LIB) $(NAME)

clean:
	@echo "Cleaning object files..."
	@$(RM) $(OBJ_1) $(OBJ_2) $(BONUS_OBJ)
	@echo "Cleaning libft object files..."
	@make -C $(LIBFTDIR) clean
	@rm -rf $(LIBFT_OBJ)
	@rm -rf $(OBJ_DIR)
	@echo "Object files cleaned."

fclean: clean
	@echo "Cleaning libft..."
	@make -C $(LIBFTDIR) fclean
	@echo "Cleaning executable..."
	@$(RM) $(NAME)
	@rm -rf $(OBJ_DIR)
	@rm -rf $(LIBFT_OBJ)
	@clear
	@echo "Executable and libft cleaned."

re: fclean all

.PHONY: all clean fclean re