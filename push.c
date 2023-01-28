/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:28:20 by mfadil            #+#    #+#             */
/*   Updated: 2023/01/27 19:31:21 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Pushes The top element of src stack to the top of dest stack
static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

//	Pushes the top of the first element of stack b to the top of stack a.
//	Prints "pa" in the standard output.
void	push_to_a(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pa\n");
}

// push_to_b:
//	- Pushes the top of the first element of stack b to the top of stack a
//	- Prints "pa" in the standard output
void	push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_b);
	ft_putstr("pb\n");
}
