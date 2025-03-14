NAME = cub3D
NAMEB = cub3D_bonus

# Source files for bonus
BSRCP = Bonus/Parse/get_next_line/get_next_line.c Bonus/Parse/get_next_line/get_next_line_utils.c \
		Bonus/Parse/libft/ft_strncmp.c Bonus/Parse/libft/ft_error.c \
		Bonus/Parse/parsing_cub/ft_parsing.c Bonus/Parse/parsing_cub/util1.c Bonus/Parse/parsing_cub/util2.c\
		Bonus/Parse/parsing_cub/util3.c Bonus/Parse/parsing_cub/util4.c Bonus/Parse/parsing_cub/util5.c Bonus/Parse/mini_m.c\
		Bonus/Parse/parsing_cub/util6.c Bonus/Parse/parsing_cub/util7.c Bonus/Parse/parsing_cub/util8.c\
		Bonus/Parse/parsing_cub/util9.c Bonus/Parse/parsing_cub/util10.c Bonus/Parse/parsing_cub/util11.c\
		Bonus/Parse/parsing_cub/util12.c Bonus/Parse/parsing_cub/util13.c Bonus/Parse/mini_map_util.c\

BSRCR = Bonus/Raycast/Raycasting.c Bonus/Raycast/checker.c Bonus/Raycast/math_formulas.c Bonus/Raycast/randering.c \
		Bonus/Raycast/run_game.c Bonus/Raycast/setter_for_data.c Bonus/Raycast/moves.c Bonus/Raycast/mouse_mv.c\
		Bonus/Raycast/free_mx.c

# Source files for mandatory
MSRCP = Mandatory/Parse/get_next_line/get_next_line.c Mandatory/Parse/get_next_line/get_next_line_utils.c \
		Mandatory/Parse/libft/ft_strncmp.c Mandatory/Parse/libft/ft_error.c \
		Mandatory/Parse/parsing_cub/ft_parsing.c Mandatory/Parse/parsing_cub/util1.c Mandatory/Parse/parsing_cub/util2.c\
		Mandatory/Parse/parsing_cub/util3.c Mandatory/Parse/parsing_cub/util4.c Mandatory/Parse/parsing_cub/util5.c\
		Mandatory/Parse/parsing_cub/util6.c Mandatory/Parse/parsing_cub/util7.c Mandatory/Parse/parsing_cub/util8.c\
		Mandatory/Parse/parsing_cub/util9.c Mandatory/Parse/parsing_cub/util10.c Mandatory/Parse/parsing_cub/util11.c\
		Mandatory/Parse/parsing_cub/util12.c

MSRCR = Mandatory/Raycast/Raycasting.c Mandatory/Raycast/checker.c Mandatory/Raycast/math_formulas.c Mandatory/Raycast/randering.c \
		Mandatory/Raycast/run_game.c Mandatory/Raycast/setter_for_data.c Mandatory/Raycast/moves.c Mandatory/Raycast/ft_free_mx.c

SRCSM = $(MSRCP) $(MSRCR) Mandatory/main.c
OBJSM = $(SRCSM:.c=.o)

SRCSB = $(BSRCP) $(BSRCR) Bonus/main.c
OBJSB = $(SRCSB:.c=.o)

CFLAGS = -Wall -Wextra -Werror -O3

MLX42 = MLX42/build/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

RM = rm -rf
CC = cc


RED = \033[0;31m
GREEN = \033[0;32m


all: $(NAME)

bon: $(NAMEB)

$(NAME): $(OBJSM)
	@$(CC) $(MLX42) $(OBJSM) -o $(NAME)
	@echo "$(GREEN)make cub3d_mandatory"


$(NAMEB): $(OBJSB)
	@$(CC) $(MLX42) $(OBJSB) -o $(NAMEB) 
	@echo "$(GREEN)make cub3d_bonus"


Mandatory/%.o: Mandatory/%.c Mandatory/Includs/raycast.h Mandatory/Parse/get_next_line/get_next_line.h Mandatory/Includs/parse.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN) Compiling $@"


Bonus/%.o: Bonus/%.c Bonus/Includs/raycast_bonus.h Bonus/Parse/get_next_line/get_next_line.h Bonus/Includs/parse_bonus.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN) Compiling $@"


clean:
	@$(RM) $(OBJSM) $(OBJSB)
	@echo "$(RED) Cleaned object files"

fclean: clean
	@$(RM) $(NAME) $(NAMEB)
	@echo "$(RED) Cleaned binaries"

re: fclean all
