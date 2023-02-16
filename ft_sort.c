/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:39:21 by mfadil            #+#    #+#             */
/*   Updated: 2023/02/15 12:18:34 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

	//int	i;
	//int	size;
	//int	pushed_b;

	//size = sizeof_stack(*stack_a);
	//i = 0;
	//pushed_b = 0;
	//while (size > 6 && i < size && pushed_b < size / 2)
	//{
	//	if ((*stack_a)->index <= size / 2)
	//	{
	//		push_to_b(stack_a, stack_b);
	//		pushed_b++;
	//	}
	//	else
	//		rotate_a(stack_a);
	//	i++;
	//}
	//while (size - pushed_b > 3)
	//{
	//	push_to_b(stack_a, stack_b);
	//	pushed_b++;
	//}
static void	save_three(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = sizeof_stack(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			push_to_b(stack_a, stack_b);
			pushed++;
		}
		else
			rotate_a(stack_a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		push_to_b(stack_a, stack_b);
		pushed++;
	}
}

//static void	shift_stack(t_stack **stack)
//{
//	int	low_pos;
//	int	size;

//	size = sizeof_stack(*stack);
//	low_pos = lowest_index_position(stack);
//	if (low_pos > size / 2)
//	{
//		while (low_pos < size)
//		{
//			rev_rotate_a(stack);
//			low_pos++;
//		}
//	}
//	else
//	{
//		while (low_pos > 0)
//		{
//			rotate_a(stack);
//			low_pos--;
//		}
//	}
//}

static void	shift_stack(t_stack **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = sizeof_stack(*stack_a);
	lowest_pos = lowest_index_position(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			rev_rotate_a(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			rotate_a(stack_a);
			lowest_pos--;
		}
	}
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	save_three(stack_a, stack_b);
	mini_sort(stack_a);
	while (*stack_b)
	{
		ft_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_shortest_move(stack_a, stack_b);
	}
	if (!check_sort(*stack_a))
		shift_stack(stack_a);
}
