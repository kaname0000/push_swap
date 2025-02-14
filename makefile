# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okaname <okaname@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/19 14:57:27 by okaname           #+#    #+#              #
#    Updated: 2025/01/29 21:47:31 by okaname          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror -I./includes 

INCLUDES = -I./includes

LIBFTDIR = ./libft

LIBFT = $(LIBFTDIR)/libft.a

SRCS =  main.c \
		make_list/ft_make_list.c \
		make_list/utils.c \
		operations/push.c \
		operations/swap.c \
		operations/rotate.c \
		sort_algo/sort.c \
		sort_algo/sort2.c \


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

$(LIBFT):
	make bonus -C $(LIBFTDIR) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) 
	make -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re