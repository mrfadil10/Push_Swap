/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 02:05:49 by mfadil            #+#    #+#             */
/*   Updated: 2023/04/08 18:36:37 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_ra(t_list **a)
{
	t_list	*first;
	t_list	*last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	last = *a;
	first = *a;
	while (last->next)
		last = last->next;
	*a = first->next;
	first->next = NULL;
	last->next = first;
	return ;
}

void	check_rb(t_list **b)
{
	t_list	*first;
	t_list	*last;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	last = *b;
	first = *b;
	while (last->next)
		last = last->next;
	*b = first->next;
	first->next = NULL;
	last->next = first;
	return ;
}

void	check_rr(t_list **a, t_list **b)
{
	t_list	*first;
	t_list	*last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	last = *a;
	while (last->next)
		last = last->next;
	*a = first->next;
	first->next = NULL;
	last->next = first;
	if (*b == NULL || (*b)->next == NULL)
		return ;
	first = *b;
	last = *b;
	while (last->next)
		last = last->next;
	*b = first->next;
	first->next = NULL;
	last->next = first;
	return ;
}
