/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:30:20 by mfadil            #+#    #+#             */
/*   Updated: 2023/02/10 17:04:58 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// The first element in the stack sent to the bottom
static void	ft_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = stack_bottom(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

// Send the first element in the stack a to the bottom
// Print "ra" to the standard output

void	rotate_a(t_stack **stack_a)
{
	ft_rotate(stack_a);
	ft_putstr("ra\n");
}

// The same for stack b
void	rotate_b(t_stack **stack_b)
{
	ft_rotate(stack_b);
	ft_putstr("rb\n");
}

// rotate the both stack a and stack b
void	rotate_all(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_putstr("rr\n");
}
