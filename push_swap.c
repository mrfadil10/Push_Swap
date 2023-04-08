/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 23:07:53 by mfadil            #+#    #+#             */
/*   Updated: 2023/04/08 00:54:23 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	keep_three(t_stack **a, t_stack **b)
{
	int	size;
	int	pushed;
	int	i;

	size = sizeof_stack(*a);
	pushed = 0;
	i = 0;
	while (size > 6 && i < size && pushed < size / 2)
	{
		if ((*a)->index <= size / 2)
		{
			push_to_b(a, b);
			pushed++;
		}
		else
			rotate_a(a);
		i++;
	}
	while (size - pushed > 3)
	{
		push_to_b(a, b);
		pushed++;
	}
}

//pushed in line 38 can be deleted
// i in line 33

static void	sort_stack(t_stack **a)
{
	int	lowest_p;
	int	size;

	size = sizeof_stack(*a);
	lowest_p = low_index_position(a);
	if (lowest_p > size / 2)
	{
		while (lowest_p < size)
		{
			reverse_rotate_a(a);
			lowest_p++;
		}
	}
	else
	{
		while (lowest_p > 0)
		{
			rotate_a(a);
			lowest_p--;
		}
	}
}

void	ft_sort(t_stack **a, t_stack **b)
{
	keep_three(a, b);
	mini_sort(a);
	while (*b)
	{
		get_target_position(a, b);
		get_cost(a, b);
		reduce_moves(a, b);
	}
	if (!stack_sort_check(*a))
		sort_stack(a);
}

void	push_swap(t_stack **a, t_stack **b, int size)
{
	if (size == 2 && !stack_sort_check(*a))
		swap_a(a);
	else if (size == 3)
		mini_sort(a);
	else if (size > 3 && !stack_sort_check(*a))
		ft_sort(a, b);
}
