/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 01:45:10 by mfadil            #+#    #+#             */
/*   Updated: 2023/03/28 02:05:23 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_sa(t_list **a)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *a;
	tmp2 = tmp->next;
	*a = tmp2;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	return ;
}

void	check_sb(t_list **b)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *b;
	tmp2 = tmp->next;
	*b = tmp2;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	return ;
}

void	check_ss(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *a;
	tmp2 = tmp->next;
	*a = tmp2;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	tmp = NULL;
	tmp2 = NULL;
	tmp = *b;
	tmp2 = tmp->next;
	*b = tmp2;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	return ;
}
