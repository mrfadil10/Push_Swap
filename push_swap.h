/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:29:01 by mfadil            #+#    #+#             */
/*   Updated: 2023/02/06 23:33:25 by mfadil           ###   ########.fr       */
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

void	ft_putstr(char *str);
int		ft_atoi(const char *str);
t_stack	*stack_bottom(t_stack *stack);
int		ft_sign(int c);
int		ft_isdigit(int c);
int		strcmp_numbers(const char *s1, const char *s2);

int		check_correct_input(char **av);
int		check_is_zero(char *av);
int		check_sort(t_stack *stack);

void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	do_ss(t_stack **stack_a, t_stack **stack_b);

void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	rotate_all(t_stack **stack_a, t_stack **stack_b);

void	rev_rotate_a(t_stack **stack_a);
void	rev_rotate_b(t_stack **stack_b);
void	rev_rotate_all(t_stack **stack_a, t_stack **stack_b);

void	push_to_a(t_stack **stack_a, t_stack **stack_b);
void	push_to_b(t_stack **stack_a, t_stack **stack_b);

int		sizeof_stack(t_stack *stack);
void	mini_sort(t_stack **stack);

void	free_stack(t_stack **stack);
void	error(t_stack **a, t_stack **b);
t_stack	*new_stack(int data);
void	add_bottom_of_stack(t_stack **stack, t_stack *new);

#endif