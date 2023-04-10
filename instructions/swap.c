/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 22:19:09 by mfadil            #+#    #+#             */
/*   Updated: 2023/04/10 23:33:36 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*var;

	if (!(*stack) || (*stack)->next == NULL)
		return ;
	var = *stack;
	*stack = (*stack)->next;
	var->next = (*stack)->next;
	(*stack)->next = var;
}

void	swap_a(t_stack **a)
{
	swap(a);
	ft_putstr("sa\n");
}

void	swap_b(t_stack **b)
{
	swap(b);
	ft_putstr("sb\n");
}

void	swap_all(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_putstr("ss\n");
}
