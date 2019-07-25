# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/17 22:34:46 by rotrojan          #+#    #+#              #
#    Updated: 2019/07/25 01:53:01 by rotrojan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_putstr.c		\
				ft_putnbr.c		\
				ft_atoi.c		\
				ft_add.c		\
				ft_sub.c		\
				ft_mul.c		\
				ft_div.c		\
				ft_mod.c		\
				do_op.c			\
				main.c
SRCS_PATH	=	./srcs/
OBJS		=	$(addprefix $(SRCS_PATH), $(SRCS:.c=.o))
INCLUDES	=	-I./includes/
NAME		=	do-op
CC			=	gcc
CFLAGS		+=	-Wall -Wextra -Werror
RM			=	rm -f

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

.c.o:
				$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re

