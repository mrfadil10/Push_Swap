/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_and_assign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 23:07:53 by mfadil            #+#    #+#             */
/*   Updated: 2023/02/11 14:28:38 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_stack_a(int argc, char **argv)
{
	t_stack		*stack;
	long int	nbr;
	int			i;

	stack = NULL;
	nbr = 0;
	i = 1;
	while (i < argc)
	{
		nbr = ft_atoi(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error(&stack, NULL);
		if (i == 1)
			stack = new_stack((int)nbr);
		else
			add_bottom_of_stack(&stack, new_stack((int)nbr));
		i++;
	}
	return (stack);
}

void	put_index_to_data(t_stack *stack, int size)
{
	int		data;
	t_stack	*highest;
	t_stack	*p;

	while (--size > 0)
	{
		p = stack;
		data = INT_MIN;
		highest = NULL;
		while (p)
		{
			if (p->data == INT_MIN && p->index == 0)
				p->index = 1;
			if (p->data > data && p->index == 0)
			{
				data = p->data;
				highest = p;
				p = stack;
			}
			else
				p = p->next;
		}
		if (highest != NULL)
			highest->index = size;
	}
}
