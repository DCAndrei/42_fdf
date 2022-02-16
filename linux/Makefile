# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/28 21:01:19 by acretu            #+#    #+#              #
#    Updated: 2022/02/13 20:16:26 by acretu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

RM		=	rm -f

NAME	=	fdf

FILES	= 	main.c \
			conversion_utils.c \
			get_next_line_utils.c \
			get_next_line.c \
			list_utils.c \
			print_helpers.c \
			general_utils.c \
			window_helpers.c \
			draw_line_helpers.c \
			rotate_utils.c \
			helper_functions.c \
			decide_helpers.c \
			display_helpers.c \
			draw_line_helpers_2.c \
			conversion_utils_2.c \
			libft_utils.c
OBJ		=	main.o \
			conversion_utils.o \
			get_next_line_utils.o \
			get_next_line.o \
			list_utils.o \
			print_helpers.o \
			general_utils.o \
			window_helpers.o \
			draw_line_helpers.o \
			rotate_utils.o \
			helper_functions.o \
			decide_helpers.o \
			display_helpers.o \
			draw_line_helpers_2.o \
			conversion_utils_2.o \
			libft_utils.o
			
MINILIBX_DIR = ./mlx_linux

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

all:	${NAME}

$(NAME): $(OBJ)
	make all -C $(MINILIBX_DIR)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean: 
			$(RM) $(OBJ)

bonus:	all

fclean: 	clean
			$(RM) $(NAME)
			@make clean -C $(MINILIBX_DIR)

re: 		fclean all

.PHONY: 	all clean fclean re