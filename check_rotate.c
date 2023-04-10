/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 02:05:49 by mfadil            #+#    #+#             */
/*   Updated: 2023/04/10 14:42:47 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	first = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
	return ;
}

void	check_ra(t_list **a)
{
	check_rotate(a);
}

void	check_rb(t_list **b)
{
	check_rotate(b);
}

void	check_rr(t_list **a, t_list **b)
{
	check_ra(a);
	check_rb(b);
}
