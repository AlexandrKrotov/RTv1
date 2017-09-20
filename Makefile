# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akrotov <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/12 15:31:28 by akrotov           #+#    #+#              #
#    Updated: 2017/09/17 18:08:17 by akrotov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===== Colors =====
END:="\033[0;0m"
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;36m"
PURPLE:="\033[1;35m"
WHITE:="\033[1;37m"
#===================

NAME = RTv1

SOURCE = ft_blur.c \
		additional_ft.c \
		ft_add_light_spot.c \
		ft_cone.c \
		ft_cylinder.c \
		ft_error.c \
		ft_exit.c \
		ft_init_all.c \
		ft_init_scene_part1.c \
		ft_init_scene_part2.c \
		ft_key_hook.c \
		ft_light.c \
		ft_mous_hook.c \
		ft_phong.c \
		ft_plane.c \
		ft_random.c \
		ft_render.c \
		ft_sphere.c \
		ft_vector_math_part1.c \
		ft_vector_math_part2.c \
		ft_vector_math_part3.c \
		main.c

SRCPATH = SRC
HDRPATH = includes
OBJPATH = obj
LIBPATH = libft

CC = gcc

FLAGS = -Wall -Wextra -Werror -I $(HDRPATH)

MLX = -lmlx -framework OpenGL -framework AppKit

LIB = -L $(LIBPATH) -lft -lm

OBJ = $(addprefix $(OBJPATH)/,$(SOURCE:.c=.o))

INC = -I $(HDRPATH) -I $(LIBPATH)

all: load lib $(NAME)

lib:
	@make -C $(LIBPATH)

load:
	@echo $(CYAN) "     LOADING"

$(NAME): $(OBJ)
	@echo $(END)
	@$(CC) $(FLAGS) -o $(NAME) $(LIB) $(MLX) $^
	@echo $(GREEN)"   $(NAME) installed"$(END)

$(OBJPATH)/%.o: $(SRCPATH)/%.c
	@echo ".\c"
	@mkdir $(OBJPATH) 2> /dev/null || true
	@clang $(FLAGS) $(INC) -o $@ -c $<

clean:
	@make clean -C $(LIBPATH)
	@rm -rf $(OBJPATH)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBPATH)
	@echo '\033[0;31m'"$(NAME) uninstalled"'\033[0m'

re: fclean all

norm:
	@norminette SRC/$(SRC)
	@norminette $(HDRPATH)/*.h

.PHONY: all lib clean fclean re norm