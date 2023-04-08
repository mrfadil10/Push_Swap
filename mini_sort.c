/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:41:48 by mfadil            #+#    #+#             */
/*   Updated: 2023/04/07 21:42:19 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_highest_index(t_stack *stack)
{
	int	i;

	i = stack->index;
	while (stack)
	{
		if (stack->index > i)
			i = stack->index;
		stack = stack->next;
	}
	return (i);
}

void	mini_sort(t_stack **stack)
{
	int	big;

	if (stack_sort_check(*stack))
		return ;
	big = get_highest_index(*stack);
	if ((*stack)->index == big)
		rotate_a(stack);
	else if ((*stack)->next->index == big)
		reverse_rotate_a(stack);
	if ((*stack)->index > (*stack)->next->index)
		swap_a(stack);
}
