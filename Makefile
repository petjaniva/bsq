# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkandemi <bkandemi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/16 14:08:19 by pniva             #+#    #+#              #
#    Updated: 2021/06/16 18:06:19 by bkandemi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
C_FILES = srcs/fillprint.c srcs/ft.c srcs/main.c srcs/map_to_matrix.c \
srcs/map.c srcs/read.c srcs/solver.c srcs/ft_err.c
HEADER = includes/


all:	$(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -o $(NAME) $(C_FILES) -I$(HEADER)

clean:
	rm -f *.o
 
fclean:
	rm -f $(NAME)

re:		fclean all