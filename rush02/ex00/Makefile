NAME = rush-02
PATH = ./srcs/
SRCS = $(PATH)error.c $(PATH)ft_atoi.c $(PATH)ft_putstr.c \
	   $(PATH)ft_split.c $(PATH)ft_sort_string_tab.c $(PATH)ft_strjoin.c \
	   $(PATH)main.c $(PATH)parse_dict.c $(PATH)extract_dict.c \
	   $(PATH)ft_strlen.c $(PATH)ft_swap.c $(PATH)ft_printdict.c
OBJS = $(SRCS:.c=.o)
INCLUDES = ./includes/
RM = rm -rf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDES)

all : $(NAME)

$(NAME):$(OBJS)
	gcc $(CFLAGS) $(OBJS) -o $(NAME)

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
