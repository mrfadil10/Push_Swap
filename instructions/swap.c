/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 22:19:09 by mfadil            #+#    #+#             */
/*   Updated: 2023/03/27 16:31:17 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!(*stack) || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	swap_a(t_stack **stack_a)
{
	swap(stack_a);
	ft_putstr("sa\n");
}

void	swap_b(t_stack **stack_b)
{
	swap(stack_b);
	ft_putstr("sb\n");
}

void	swap_all(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr("ss\n");
}
