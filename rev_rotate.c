/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:03:45 by mfadil            #+#    #+#             */
/*   Updated: 2023/03/25 17:55:15 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//// Bring the bottom element of a stack to the top
//static void	rev_rotate(t_stack **stack)
//{
//	t_stack	*tmp;
//	t_stack	*tail;
//	t_stack	*before_tail;

//	tail = stack_bottom(*stack);
//	before_tail = stack_before_bottom(*stack);
//	tmp = *stack;
//	*stack = tail;
//	(*stack)->next = tmp;
//	before_tail->next = NULL;
//}

//// Bring the bottom element of stack a to the top
//void	rev_rotate_a(t_stack **stack_a)
//{
//	rev_rotate(stack_a);
//	ft_putstr("rra\n");
//}

//// The same for the stack b
//void	rev_rotate_b(t_stack **stack_b)
//{
//	rev_rotate(stack_b);
//	ft_putstr("rrb\n");
//}

//// reverse rotate the both stack a and stack b

//void	rev_rotate_all(t_stack **stack_a, t_stack **stack_b)
//{
//	rev_rotate_a(stack_a);
//	rev_rotate_b(stack_b);
//	ft_putstr("rrr\n");
//}
/* Brings the bottom element of a stack to the top. */

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

/*	Brings the bottom element of stack a to the top.
	Prints "rra" to the standard output. */

void	do_rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
	ft_putstr("rra\n");
}

/*  Brings the bottom element of stack b to the top.
    Prints "rrb" to the standard output. */

void	do_rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
	ft_putstr("rrb\n");
}

/*	Brings the bottom element of both stack a and stack be to the top of
	their stacks. Prints "rrr" to the standard output. */

void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_putstr("rrr\n");
}
