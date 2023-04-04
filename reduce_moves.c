/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:33:50 by mfadil            #+#    #+#             */
/*   Updated: 2023/03/31 15:06:12 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

void	cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*b;
	int		size_a;
	int		size_b;

	a = *stack_a;
	b = *stack_b;
	size_a = sizeof_stack(a);
	size_b = sizeof_stack(b);
	while (b)
	{
		b->cost_b = b->position;
		if (b->position > size_b / 2)
			b->cost_b = (size_b - b->position) * -1;
		b->cost_a = b->tar_position;
		if (b->tar_position > size_a / 2)
			b->cost_a = (size_a - b->tar_position) * -1;
		b = b->next;
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
		if (ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b) < cheapest)
		{
			cheapest = ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	do_best_move(stack_a, stack_b, cost_a, cost_b);
}
