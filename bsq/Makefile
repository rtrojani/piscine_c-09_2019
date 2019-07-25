# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/17 22:34:46 by rotrojan          #+#    #+#              #
#    Updated: 2019/07/24 22:40:49 by lucocozz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= 			bsq

SRC_FILE=		ft_check_error.c	\
				ft_matrice.c		\
				ft_parsing.c		\
				ft_stdin.c			\
				ft_print_square.c

SRC_PATH= srcs/

SRC= $(addprefix $(SRC_PATH), $(SRC_FILE))

INCL_PATH= -I includes/

LIB=	-L lib/ -lft -llist

FLAGS= -Wall -Werror -Wextra -o

$(NAME):
	gcc $(FLAGS) $(NAME) main.c $(SRC) $(LIB) $(INCL_PATH)

all: $(NAME)

clean:
	rm -f .input.map

fclean: clean
	rm -f $(NAME)

re: fclean all
