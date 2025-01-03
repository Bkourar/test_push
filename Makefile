NAME = cub

SRCS = main.c trans_rad_deg.c run_game.c move_player.c line.c calcult.c rendring.c map_2.c
OBJS = $(SRCS:.c=.o)
CFLAGS =  -Wall -Wextra -Werror
T = MLX42/build/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
RM = rm -rf
CC = cc
RED = \033[0;31m
GREEN = \033[0;32m

all 			: $(NAME)

$(NAME)			: $(OBJS)
	$(CC) $(T) $(OBJS) -o $(NAME) -g -fsanitize=address
	@echo "$(GREEN)make cub"

%.o : %.c recast.h
	$(CC) $(CFLAGS) -c $< -o $@ -g -fsanitize=address

fclean : clean
	@$(RM) $(NAME) 
	@echo "$(RED)clean cub"

clean :
	@$(RM) $(OBJS)

re : fclean $(NAME)