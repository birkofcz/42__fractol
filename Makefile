# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 15:29:04 by sbenes            #+#    #+#              #
#    Updated: 2023/05/20 09:48:24 by sbenes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#color and formatting definitions:
BOLD =	\033[1m
GREEN =	\033[32m
RED =	\033[31m
NC =	\033[0m


#name
NAME = 		fractol

# compiler
CC =		cc
CFLAGS =	-Wall -Wextra -Werror

#Minilibx
MLX_PATH =	mlx/
MLX_NAME =	libmlx.a
MLX =		$(MLX_PATH)$(MLX_NAME)

#libft
LIBFT_PATH =	libft/
LIBFT_NAME =	libft.a
LIBFT =			$(LIBFT_PATH)$(LIBFT_NAME)

#Includes
INC =	-I ./include/\
		-I ./libft/\
		-I ./mlx/

#sources
SRC_PATH =	src/
SRC = 	fractol.c init.c args.c exit.c help.c utilities.c render.c\
		event_hq.c events.c colors.c legend.c \
		SET_mandelbrot.c SET_julia.c SET_burning_ship.c
SRCS =	$(addprefix $(SRC_PATH), $(SRC))

#objects
OBJ_PATH =	obj/
OBJ =		$(SRC:.c=.o)
OBJS =		$(addprefix $(OBJ_PATH), $(OBJ))


all: $(MLX) $(LIBFT) $(NAME)

$(OBJ_PATH)%.o :$(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(MLX):
	@echo "$(BOLD)$(GREEN)[ 🙈 Making MiniLibX... ]$(NC)"
	@make -sC $(MLX_PATH)

$(LIBFT):
	@echo "$(BOLD)$(GREEN)[ 🙉 Making libft... ]$(NC)"
	@make -sC $(LIBFT_PATH)

$(NAME): $(OBJS)
	@echo "$(BOLD)$(GREEN)[ 🙊 Compiling shit together... ]$(NC)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(INC) -lXext -lX11 -lm
	@echo "$(BOLD)$(GREEN)[ 🪄 Program ready! ]$(NC)"
	@echo ""
	@echo "$(BOLD)[ -- Welcome to Fract'ol -- ]$(NC)"
	@echo ""
	@echo "$(BOLD)run ./fractol <fractal_set> <opt:julia_param1> <opt:julia_param2>$(NC)"
	@echo ""
	@echo "Mandelbrot:   '1' or 'mandelbrot'"
	@echo "Julia:        '2' or 'julia'"
	@echo "Burning ship: '3' or 'ship'"
	@echo ""
	@echo "Julia parameters are optional."
	@echo ""
	@echo "[ -- Have fun ! 😉 -- ]"
	@echo ""

bonus: all

clean:
	@echo "$(BOLD)$(RED)[ 🔥 Purging object files ]$(NC)"
	@rm -Rf $(OBJ_PATH)
	@make clean -sC $(MLX_PATH)
	@make clean -sC $(LIBFT_PATH)

fclean:
	@echo "$(BOLD)$(RED)[ 🔥 Removing program ]$(NC)"
	@rm -f $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re: fclean all

.PHONY: all re clean fclean


 
