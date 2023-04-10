/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 01:45:10 by mfadil            #+#    #+#             */
/*   Updated: 2023/04/10 16:41:21 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_sa(t_list **a)
{
	t_list	*var1;
	t_list	*var2;

	var1 = *a;
	var2 = var1->next;
	*a = var2;
	var1->next = var2->next;
	var2->next = var1;
	return ;
}

void	check_sb(t_list **b)
{
	t_list	*var1;
	t_list	*var2;

	var1 = *b;
	var2 = var1->next;
	*b = var2;
	var1->next = var2->next;
	var2->next = var1;
	return ;
}

void	check_ss(t_list **a, t_list **b)
{
	t_list	*var1;
	t_list	*var2;

	var1 = *a;
	var2 = var1->next;
	*a = var2;
	var1->next = var2->next;
	var2->next = var1;
	var1 = NULL;
	var2 = NULL;
	var1 = *b;
	var2 = var1->next;
	*b = var2;
	var1->next = var2->next;
	var2->next = var1;
	return ;
}
