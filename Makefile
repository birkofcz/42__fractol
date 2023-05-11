# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 15:29:04 by sbenes            #+#    #+#              #
#    Updated: 2023/05/11 16:25:40 by sbenes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
SRC = 	fractol.c mandelbrot.c julia.c init.c args.c exit.c help.c utilities.c render.c\
		events.c
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
	@echo "[ Making MiniLibX ]"
	@make -sC $(MLX_PATH)

$(LIBFT):
	@echo "[ Making libft ]"
	@make -sC $(LIBFT_PATH)

$(NAME): $(OBJS)
	@echo "[ Compiling program ]"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(INC) -lXext -lX11 -lm
	@echo "[ Program ready! ]"

bonus: all

clean:
	@echo "[ Removing object files ]"
	@rm -Rf $(OBJ_PATH)
	@make clean -sC $(MLX_PATH)
	@make clean -sC $(LIBFT_PATH)

fclean:
	@echo "[ Removing program ]"
	@rm -f $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re: fclean all

.PHONY: all re clean fclean


 
