/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:03:45 by mfadil            #+#    #+#             */
/*   Updated: 2023/03/27 16:59:22 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*new_tail;

	tail = get_bottom(*stack);
	new_tail = before_bottom(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	new_tail->next = NULL;
}

void	reverse_rotate_a(t_stack **stack_a)
{
	rev_rotate(stack_a);
	ft_putstr("rra\n");
}

void	reverse_rotate_b(t_stack **stack_b)
{
	rev_rotate(stack_b);
	ft_putstr("rrb\n");
}

void	reverse_rotate_all(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_putstr("rrr\n");
}
