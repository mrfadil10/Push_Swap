/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:29:01 by mfadil            #+#    #+#             */
/*   Updated: 2023/02/15 16:17:03 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stddef.h>

typedef struct s_stack
{
	int				data;
	int				index;
	int				position;
	int				tar_position;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

t_stack		*fill_stack_a(int argc, char **argv);
void		put_index_to_data(t_stack *stack, int size);

void		ft_target_position(t_stack **stack_a, t_stack **stack_b);
int			lowest_index_position(t_stack **stack);

void		do_shortest_move(t_stack **stack_a, t_stack **stack_b);
void		get_cost(t_stack **stack_a, t_stack **stack_b);

void		ft_putstr(char *str);
t_stack		*stack_bottom(t_stack *stack);
long int	ft_atoi(const char *str);

int			check_sort(t_stack *stack);

void		ft_moves(t_stack **a, t_stack **b, int cost_a, int cost_b);

void		swap_a(t_stack **stack_a);
void		swap_b(t_stack **stack_b);
void		do_ss(t_stack **stack_a, t_stack **stack_b);
void		rotate_a(t_stack **stack_a);
void		rotate_b(t_stack **stack_b);
void		rotate_all(t_stack **stack_a, t_stack **stack_b);
void		rev_rotate_a(t_stack **stack_a);
void		rev_rotate_b(t_stack **stack_b);
void		rev_rotate_all(t_stack **stack_a, t_stack **stack_b);

void		push_to_a(t_stack **stack_a, t_stack **stack_b);
void		push_to_b(t_stack **stack_a, t_stack **stack_b);

int			sizeof_stack(t_stack *stack);
void		mini_sort(t_stack **stack);
void		free_stack(t_stack **stack);

void		error(t_stack **a, t_stack **b);

t_stack		*new_stack(int data);
void		add_bottom_of_stack(t_stack **stack, t_stack *new);
void		ft_sort(t_stack **stack_a, t_stack **stack_b);
int			va_abs(int nbr);
t_stack		*stack_before_bottom(t_stack *stack);

int			check_correct_input(char **av);
int			ft_sign(char c);
int			ft_isdigit(char c);
int			strcmp_numbers(const char *s1, const char *s2);

#endif