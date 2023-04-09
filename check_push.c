/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 01:12:07 by mfadil            #+#    #+#             */
/*   Updated: 2023/04/08 18:31:25 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_pa(t_list **b, t_list **a)
{
	t_list	*var;

	if (*b == NULL)
		return ;
	var = *b;
	*b = (*b)->next;
	var->next = *a;
	*a = var;
	return ;
}

void	check_pb(t_list **a, t_list **b)
{
	t_list	*var;

	if (*a == NULL)
		return ;
	var = *a;
	*a = (*a)->next;
	var->next = *b;
	*b = var;
	return ;
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	s = malloc(count * size);
	if (s == NULL)
		return (s);
	ft_bzero(s, size * count);
	return (s);
}
