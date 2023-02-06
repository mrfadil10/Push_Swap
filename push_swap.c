/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 23:07:53 by mfadil            #+#    #+#             */
/*   Updated: 2023/02/06 23:34:39 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_stack_a(int argc, char **argv)
{
	t_stack	*stack;
	int		nbr;
	int		i;

	stack = NULL;
	nbr = 0;
	i = 0;
	while (i < argc)
	{
		nbr = ft_atoi(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error(&stack, NULL);
		if (i == 1)
			stack = new_stack(nbr);
		else
			add_bottom_of_stack(&stack, new_stack(nbr));
		i++;
	}
}
