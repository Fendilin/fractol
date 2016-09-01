
CC = clang
FLAGS = -Werror -Wall -Wextra -O3 -g3
INC = -I ./include/ -I ./libft/include -I ./minilibx_macos/
LIBFT_DIR = libft
MLX_DIR = minilibx_macos/
LIBFT = -L ./libft/ -lft
LIBMLX = -L ./minilibx_macos -lmlx -framework OpenGL -framework AppKit
NAME = fractol

SRC =	main.c\
		mlx_util.c\
		fractal.c\
		fract_util.c\
		color.c

TOBJ = $(SRC:.c=.o)
OBJ = $(addprefix obj/, $(TOBJ))
ODIR = obj
SDIR = src
HFILES = include/fractol.h

all: $(NAME)

$(NAME): $(OBJ)
	@(cd $(LIBFT_DIR) && $(MAKE))
	@echo "- LIBFT Done -"
	@(cd $(MLX_DIR) && $(MAKE))
	@echo "- MLX Done -"
	@$(CC) -o $(NAME) $(OBJ) $(LIBMLX) $(LIBFT)
	@echo "- LINK Done -"

$(ODIR)/%.o: $(SDIR)/%.c $(HFILES)
	@mkdir -p $(ODIR)
	@$(CC) $(FLAGS) -c $(INC) -o $@ $<
	@echo "- COMPIL' $@ Done -"

clean:
	@(cd $(LIBFT_DIR) && $(MAKE) $@)
	@(cd $(MLX_DIR) && $(MAKE) $@)
	@rm -rf $(OBJ)
	@echo "- CLEAN Done -"

fclean: clean
	@(cd $(LIBFT_DIR) && $(MAKE) $@)
	@rm -rf $(NAME)
	@echo "- FCLEAN Done -"

re: fclean all
