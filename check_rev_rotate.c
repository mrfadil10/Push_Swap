/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rev_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 03:48:05 by mfadil            #+#    #+#             */
/*   Updated: 2023/04/10 20:02:25 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_rra(t_list **a)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *a;
	last = *a;
	while (last->next)
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
	while (last->next)
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
	check_rra(a);
	check_rrb(b);
	return ;
}

// some utils

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
