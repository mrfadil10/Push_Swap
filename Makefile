# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/05 16:38:37 by mfadil            #+#    #+#              #
#    Updated: 2023/03/26 20:55:03 by mfadil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
NAME = push_swap
#S_PATH = src/
O_PATH = obj/

SRC =	check_input.c \
		ft_moves.c \
		ft_position.c \
		main.c \
		mini_sort.c \
		push_swap_utils.c \
		push_swap.c \
		push.c \
		reduce_moves.c \
		rev_rotate.c \
		rotate.c \
		split_strs.c \
		stack.c \
		swap.c \
		lib1.c

OBJ		= 	$(SRC:.c=.o)
SRCS	= $(addprefix $(S_PATH), $(SRC))
OBJS	= $(addprefix $(O_PATH), $(OBJ))

all: $(O_PATH) $(NAME)

$(O_PATH)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(O_PATH):
	mkdir $(O_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(O_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re