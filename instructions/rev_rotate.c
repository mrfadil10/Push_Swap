/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:03:45 by mfadil            #+#    #+#             */
/*   Updated: 2023/04/10 23:34:24 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*var;
	t_stack	*new;
	t_stack	*tail;

	tail = get_last_element(*stack);
	new = get_before_last(*stack);
	var = *stack;
	*stack = tail;
	(*stack)->next = var;
	new->next = NULL;
}

void	reverse_rotate_a(t_stack **a)
{
	rev_rotate(a);
	ft_putstr("rra\n");
}

void	reverse_rotate_b(t_stack **b)
{
	rev_rotate(b);
	ft_putstr("rrb\n");
}

void	reverse_rotate_all(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_putstr("rrr\n");
}
