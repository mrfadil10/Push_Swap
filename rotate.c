/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:30:20 by mfadil            #+#    #+#             */
/*   Updated: 2023/03/25 00:55:20 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//// The first element in the stack sent to the bottom
//static void	ft_rotate(t_stack **stack)
//{
//	t_stack	*tmp;
//	t_stack	*tail;

//	tmp = *stack;
//	*stack = (*stack)->next;
//	tail = stack_bottom(*stack);
//	tmp->next = NULL;
//	tail->next = tmp;
//}

//// Send the first element in the stack a to the bottom
//// Print "ra" to the standard output

//void	rotate_a(t_stack **stack_a)
//{
//	ft_rotate(stack_a);
//	ft_putstr("ra\n");
//}

//// The same for stack b
//void	rotate_b(t_stack **stack_b)
//{
//	ft_rotate(stack_b);
//	ft_putstr("rb\n");
//}

//// rotate the both stack a and stack b
//void	rotate_all(t_stack **stack_a, t_stack **stack_b)
//{
//	ft_rotate(stack_a);
//	ft_rotate(stack_b);
//	ft_putstr("rr\n");
//}
/* The top element of the stack is sent to the bottom. */

static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = get_bottom(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

/*	Sends the top element of stack a to the bottom.
	Prints "ra" to the standard output */

void	do_ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
}

/*	Sends the top element of stack b to the bottom.
	Prints "rb" to the standard output. */

void	do_rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
}

/* Sends the top element of both stack a and stack b to the bottom
	of their stacks. Prints "rr" to the standard output. */

void	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}
