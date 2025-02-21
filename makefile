# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okaname <okaname@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/19 14:57:27 by okaname           #+#    #+#              #
#    Updated: 2025/02/08 20:54:36 by okaname          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes 

MANDATORY = push_swap
BONUS = checker

LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a

SRCS =  make_list/ft_make_list.c \
		make_list/ft_make_array.c \
		make_list/ft_lis.c \
		make_list/utils.c \
		operations/push.c \
		operations/swap.c \
		operations/rotate.c \
		operations/r_rotate.c \
		sort_algo/sort.c \
		sort_algo/sort2.c \
		sort_algo/calculate_cost.c \
		sort_algo/calculate_all.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

all: $(MANDATORY)

$(MANDATORY): $(LIBFT) $(OBJS) main.c
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) main.c -o $@

$(BONUS): $(LIBFT) $(OBJS) main_bonus.c
	$(CC) $(CFLAGS) main_bonus.c $(OBJS) $(LIBFT) -o $@


$(LIBFT):
	make -C $(LIBFTDIR) bonus

bonus: $(BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) 
	make -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(MANDATORY) $(BONUS)
	make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
