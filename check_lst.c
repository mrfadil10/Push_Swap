/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:18:47 by mfadil            #+#    #+#             */
/*   Updated: 2023/04/08 17:41:13 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	lst_check_c(t_list *a, int check)
{
	while (a->next)
	{
		if (a->content == check)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		a = a->next;
	}
	return ;
}

void	lst_order(t_list **a)
{
	t_list	*var1;
	t_list	*var2;

	var1 = *a;
	var2 = var1->next;
	while (var2)
	{
		if (var1->content > var2->content)
			return ;
		var1 = var1->next;
		var2 = var2->next;
	}
	exit (0);
}

void	check_lst_inverted(t_list **a)
{
	t_list	*var1;
	t_list	*var2;

	var1 = *a;
	var2 = var1->next;
	while (var2)
	{
		if (var1->content < var2->content)
			return ;
		var1 = var1->next;
		var2 = var2->next;
	}
	check_sa(a);
	return ;
}

void	check_write_lst(t_list **a, int ac, char **av, int i)
{
	t_list	*tmp;

	tmp = NULL;
	while (i < ac)
	{
		tmp = ft_lstnew(ft_atoi(av[i]));
		ft_lstadd_back(a, tmp);
		lst_check_c(*a, tmp->content);
		i++;
	}
	lst_order(a);
	check_lst_inverted(a);
	tmp = NULL;
}
