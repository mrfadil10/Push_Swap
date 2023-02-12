/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:39:02 by mfadil            #+#    #+#             */
/*   Updated: 2023/02/12 18:02:08 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->position = i;
		tmp = tmp->next;
		i++;
	}
}

int	lowest_index_position(t_stack **stack)
{
	t_stack	*tmp;
	int		low_i;
	int		low_pos;

	tmp = *stack;
	low_i = INT_MAX;
	get_position(stack);
	low_pos = tmp->position;
	while (tmp)
	{
		if (tmp->index < low_i)
		{
			low_i = tmp->index;
			low_pos = tmp->position;
		}
		tmp = tmp->next;
	}
	return (low_pos);
}

static int	get_target(t_stack **a, int b_index, int tar_index, int tar_pos)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->index > b_index && tmp->index < tar_index)
		{
			tar_pos = tmp->position;
			tar_index = tmp->index;
		}
		tmp = tmp->next;
	}
	if (tar_index != INT_MAX)
		return (tar_pos);
	tmp = *a;
	while (tmp)
	{
		if (tmp->index < tar_index)
		{
			tar_pos = tmp->position;
			tar_index = tmp->index;
		}
		tmp = tmp->next;
	}
	return (tar_pos);
}

void	ft_target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		tar_position;

	tmp = *stack_b;
	get_position(stack_a);
	get_position(stack_b);
	tar_position = 0;
	while (tmp)
	{
		tar_position = get_target(stack_a, tmp->index, INT_MAX, tar_position);
		tmp->tar_position = tar_position;
		tmp = tmp->next;
	}
}
