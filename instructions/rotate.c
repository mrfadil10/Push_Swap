/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:30:20 by mfadil            #+#    #+#             */
/*   Updated: 2023/04/10 23:33:57 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*tail;
	t_stack	*var;

	var = *stack;
	*stack = (*stack)->next;
	tail = get_last_element(*stack);
	var->next = NULL;
	tail->next = var;
}

void	rotate_a(t_stack **a)
{
	rotate(a);
	ft_putstr("ra\n");
}

void	rotate_b(t_stack **b)
{
	rotate(b);
	ft_putstr("rb\n");
}

void	rotate_all(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_putstr("rr\n");
}
