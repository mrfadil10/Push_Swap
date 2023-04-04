# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/05 16:38:37 by mfadil            #+#    #+#              #
#    Updated: 2023/03/30 17:15:18 by mfadil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
NAME	= push_swap
B_NAME	= checker
O_PATH	= obj/

SRC =	check_input.c \
		ft_moves.c \
		ft_position.c \
		main.c \
		mini_sort.c \
		push_swap_utils.c \
		push_swap.c \
		reduce_moves.c \
		split_strs.c \
		stack.c \
		libc.c \
		../instructions/push.c \
		../instructions/rev_rotate.c \
		../instructions/rotate.c \
		../instructions/swap.c

B_SRC = check_lst.c \
		check_push.c \
		check_rotate.c \
		check_rev_rotate.c \
		check_swap.c \
		checker_main.c \
		get_next_line.c \
		get_next_line_utils.c \
		libc_check.c \
		split_strs.c

OBJ		=	$(SRC:.c=.o)
B_OBJ	=	$(B_SRC:.c=.o)

OBJS	=	$(addprefix $(O_PATH), $(OBJ))
B_OBJS	=	$(addprefix $(O_PATH), $(B_OBJ))

all: $(O_PATH) $(NAME)

bonus: $(O_PATH) $(B_NAME)

$(O_PATH)%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

$(O_PATH):
	mkdir $(O_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(B_NAME): $(B_OBJS)
	$(CC) $(CFLAGS) $(B_OBJS) -o $(B_NAME)

clean:
	rm -rf $(O_PATH)
	rm -rf ./instructions/*.o
	rm -rf *.o

fclean: clean
	rm -f $(NAME)
	rm -f $(B_NAME)

re: fclean all

.PHONY: all bonus clean fclean re