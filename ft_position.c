/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:39:02 by mfadil            #+#    #+#             */
/*   Updated: 2023/04/09 22:15:02 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	num_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->position = i;
		tmp = tmp->next;
		i++;
	}
}

int	low_index_position(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_i;
	int		lowest_p;

	tmp = *stack;
	lowest_i = INT_MAX;
	num_position(stack);
	lowest_p = tmp->position;
	while (tmp)
	{
		if (tmp->index < lowest_i)
		{
			lowest_i = tmp->index;
			lowest_p = tmp->position;
		}
		tmp = tmp->next;
	}
	return (lowest_p);
}

static int	get_best_target(t_stack **a, int idx_b, int target_i, int target)
{
	t_stack	*stack;

	stack = *a;
	while (stack)
	{
		if (stack->index > idx_b && stack->index < target_i)
		{
			target_i = stack->index;
			target = stack->position;
		}
		stack = stack->next;
	}
	if (target_i != INT_MAX)
		return (target);
	stack = *a;
	while (stack)
	{
		if (stack->index < target_i)
		{
			target_i = stack->index;
			target = stack->position;
		}
		stack = stack->next;
	}
	return (target);
}

void	get_target_position(t_stack **stack_a, t_stack **stack_b)
{
	int		target;
	t_stack	*temp;

	temp = *stack_b;
	num_position(stack_a);
	num_position(stack_b);
	target = 0;
	while (temp)
	{
		target = get_best_target(stack_a, temp->index, INT_MAX, target);
		temp->tar_position = target;
		temp = temp->next;
	}
}
