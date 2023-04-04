/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rev_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 03:48:05 by mfadil            #+#    #+#             */
/*   Updated: 2023/03/28 16:49:34 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_rra(t_list **a)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *a;
	last = *a;
	while (last->next != NULL)
	{
		tmp = last;
		last = last->next;
	}
	last->next = *a;
	*a = last;
	tmp->next = NULL;
}

void	check_rrb(t_list **b)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *b;
	last = *b;
	while (last->next != NULL)
	{
		tmp = last;
		last = last->next;
	}
	last->next = *b;
	*b = last;
	tmp->next = NULL;
}

void	check_rrr(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *a;
	last = *a;
	while (last->next != NULL)
	{
		tmp = last;
		last = last->next;
	}
	last->next = *a;
	*a = last;
	tmp->next = NULL;
	tmp = *b;
	last = *b;
	while (last->next != NULL)
	{
		tmp = last;
		last = last->next;
	}
	last->next = *b;
	*b = last;
	tmp->next = NULL;
	return ;
}
