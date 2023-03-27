/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:33:50 by mfadil            #+#    #+#             */
/*   Updated: 2023/03/26 02:54:43 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = get_stack_size(tmp_a);
	size_b = get_stack_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->position;
		if (tmp_b->position > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->position) * -1;
		tmp_b->cost_a = tmp_b->tar_position;
		if (tmp_b->tar_position > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->tar_position) * -1;
		tmp_b = tmp_b->next;
	}
}

void	reduce_moves(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*tmp;
	int			cheapest;
	int			cost_a;
	int			cost_b;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (abs(tmp->cost_a) + abs(tmp->cost_b) < cheapest)
		{
			cheapest = abs(tmp->cost_a) + abs(tmp->cost_b);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	do_best_move(stack_a, stack_b, cost_a, cost_b);
}
