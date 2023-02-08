/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:39:21 by mfadil            #+#    #+#             */
/*   Updated: 2023/02/08 18:00:39 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	save_three(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	size;
	int	pushed_b;

	size = sizeof_stack(*stack_a);
	i = 0;
	pushed_b = 0;
	while (size > 6 && i < size && pushed_b < size / 2)
	{
		if ((*stack_a)->index <= size / 2)
		{
			push_to_b(stack_a, stack_b);
			pushed_b++;
		}
		else
			rotate_a(stack_a);
		i++;
	}
}

static void	shift_stack(t_stack **stack)
{
	int	low_pos;
	int	size;

	size = sizeof_stack(*stack);
	low_pos = lowest_index_position(stack);
	if (low_pos > size / 2)
	{
		while (low_pos < size)
		{
			rev_rotate_a(stack);
			low_pos++;
		}
	}
	else
	{
		while (low_pos > 0)
		{
			rotate_a(stack);
			low_pos--;
		}
	}
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	save_three(*stack_a, stack_b);
	mini_sort(stack_a);
	while (*stack_b)
	{
		ft_target_position(stack_a, stack_b);
	}
	if (!check_sort(*stack_a))
		shift_stack(stack_a);
}
