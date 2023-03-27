/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 22:19:09 by mfadil            #+#    #+#             */
/*   Updated: 2023/03/26 15:56:35 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap the 2 first elements of a stack
// does nothing if there is only
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

// swap the first 2 elements of stack a
// prints "sa" in the standard output
//void	swap_a(t_stack **stack_a)
//{
//	swap(stack_a);
//	ft_putstr("sa\n");
//}

//// same for stack b

//void	swap_b(t_stack **stack_b)
//{
//	swap(stack_b);
//	ft_putstr("sb\n");
//}

//// do the operation in both stack a and stack b
//void	do_ss(t_stack **stack_a, t_stack **stack_b)
//{
//	swap(stack_a);
//	swap(stack_b);
//	ft_putstr("ss\n");
//}

void	do_sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_putstr("sa\n");
}

/*	Swaps the top 2 elements of stack b. Prints "sb" to the standard output. */

void	do_sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_putstr("sb\n");
}

/*	Swaps the top 2 elements of stack a and the top 2 elements
	of stack b. Prints "ss" to the standard output. */

void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr("ss\n");
}
