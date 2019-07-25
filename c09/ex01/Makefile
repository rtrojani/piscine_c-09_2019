# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/17 22:34:46 by rotrojan          #+#    #+#              #
#    Updated: 2019/07/22 01:55:05 by rotrojan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_putchar.c	\
				ft_putstr.c		\
				ft_strlen.c		\
				ft_strcmp.c		\
				ft_swap.c
SRCS_PATH	=	./srcs/
OBJS		=	$(addprefix $(SRCS_PATH), $(SRCS:.c=.o))
INCLUDES	=	-I./includes/
NAME		=	libft.a
CC			=	gcc
CFLAGS		+=	-Wall -Wextra -Werror
LIB_MAKER	=	ar rc
LIB_INDEXER	=	ranlib
RM			=	rm -f

all:			$(NAME)

$(NAME):		$(OBJS)
				$(LIB_MAKER) $(NAME) $(OBJS)
				$(LIB_INDEXER) $(NAME)

.c.o:
				$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
