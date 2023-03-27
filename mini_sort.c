/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:41:48 by mfadil            #+#    #+#             */
/*   Updated: 2023/03/26 14:48:02 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//static int	biggest_index(t_stack *stack)
//{
//	int	index;

//	index = stack->index;
//	while (stack)
//	{
//		if (stack->index > index)
//			index = stack->index;
//		stack = stack->next;
//	}
//	return (index);
//}

//void	mini_sort(t_stack **stack)
//{
//	int	big;

//	if (check_sort(*stack))
//		return ;
//	big = biggest_index(*stack);
//	if ((*stack)->index == big)
//		rotate_a(stack);
//	else if ((*stack)->next->index == big)
//		rev_rotate_a(stack);
//	if ((*stack)->index > (*stack)->next->index)
//		swap_a(stack);
//}

static int	biggest_index(t_stack *stack)
{
	int	index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

/*	Sorts a stack of 3 numbers in 2 or fewer moves. The sorting is done by index
	rather than value. */

void	sort_three(t_stack **stack)
{
	int	biggest;

	if (is_sorted(*stack))
		return ;
	biggest = biggest_index(*stack);
	if ((*stack)->index == biggest)
		do_ra(stack);
	else if ((*stack)->next->index == biggest)
		do_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		do_sa(stack);
}
