/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 23:18:16 by mfadil            #+#    #+#             */
/*   Updated: 2023/03/26 21:35:00 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	check_input(char *av)
{
	int	i;

	i = 0;
	if ((av[i] == '-' || av[i] == '+') && (ft_strlen(av) > 1))
		i++;
	while (av[i])
	{
		if (av[i] < '0' || av[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_dup(t_stack *column)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = column;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->data == tmp2->data)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

void	get_index(t_stack *stack_a, int size)
{
	t_stack	*ptr;
	t_stack	*big;
	int		value;

	while (--size > 0)
	{
		big = NULL;
		value = INT_MIN;
		ptr = stack_a;
		while (ptr)
		{
			if (ptr->data == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->data > value && ptr->index == 0)
			{
				value = ptr->data;
				big = ptr;
				ptr = ptr->next;
			}
			else
				ptr = ptr->next;
		}
		if (big != NULL)
			big->index = size;
	}
}

void	ft_norm(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		while (av[i][j] && av[i][j] == ' ')
			j++;
		if (av[i][j] == '\0')
		{
			write(2, "Error\n", 6);
			exit (1);
		}
		i++;
	}
}

	//int		j;

	//j = 0;
	//stack_b = NULL;
	//stack_a = NULL;
	//while (av[i])
	//{
	//	while (av[i][j] && av[i][j] == ' ')
	//		j++;
	//	if (av[i][j] == '\0')
	//	{
	//		write(2, "Error\n", 6);
	//		exit (1);
	//	}
	//	i++;
	//}