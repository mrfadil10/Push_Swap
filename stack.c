/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:13:21 by mfadil            #+#    #+#             */
/*   Updated: 2023/03/25 01:17:41 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//t_stack	*stack_bottom(t_stack *stack)
//{
//	while (stack && stack->next != NULL)
//		stack = stack->next;
//	return (stack);
//}

//t_stack	*stack_before_bottom(t_stack *stack)
//{
//	while (stack && stack->next && stack->next->next != NULL)
//		stack = stack->next;
//	return (stack);
//}

//t_stack	*new_stack(int data)
//{
//	t_stack	*new;

//	new = malloc(sizeof * new);
//	if (!new)
//		return (NULL);
//	new->data = data;
//	new->index = 0;
//	new->position = -1;
//	new->tar_position = -1;
//	new->cost_a = -1;
//	new->cost_b = -1;
//	new->next = NULL;
//	return (new);
//}

//int	sizeof_stack(t_stack *stack)
//{
//	int	size;

//	size = 0;
//	if (!stack)
//		return (0);
//	while (stack)
//	{
//		stack = stack->next;
//		size++;
//	}
//	return (size);
//}

//void	add_bottom_of_stack(t_stack **stack, t_stack *new)
//{
//	t_stack	*a;

//	if (!new)
//		return ;
//	if (!*stack)
//	{
//		*stack = new;
//		return ;
//	}
//	a = stack_bottom(*stack);
//	a->next = new;
//}

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = value;
	new->index = 0;
	new->position = -1;
	new->tar_position = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

/*	Adds an element to the bottom of a stack. */

void	stack_add(t_stack **stack, t_stack *new)
{
	t_stack	*bottom;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	bottom = get_bottom(*stack);
	bottom->next = new;
}

/*	Returns the last element of the stack. */

t_stack	*get_bottom(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

/* Returns de element before the bottom element */

t_stack	*before_bottom(t_stack *stack)
{
	while (stack && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

/*	Returns the number of elements in a stack. */

int	get_stack_size(t_stack	*stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}
