/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:28:20 by mfadil            #+#    #+#             */
/*   Updated: 2023/04/10 23:31:51 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*var;

	if (*src == NULL)
		return ;
	var = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = var;
}

void	push_to_a(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_putstr("pa\n");
}

void	push_to_b(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_putstr("pb\n");
}
