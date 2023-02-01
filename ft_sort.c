/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:39:21 by mfadil            #+#    #+#             */
/*   Updated: 2023/02/01 16:01:12 by mfadil           ###   ########.fr       */
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

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	save_three(*stack_a, stack_b);
	mini_sort(stack_a);
	while (*stack_b)
	{
		
	}
}
