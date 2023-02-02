/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:39:02 by mfadil            #+#    #+#             */
/*   Updated: 2023/02/02 23:41:49 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

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
	low_i = tmp->position;
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

static int	get_target(t_stack **a, int)