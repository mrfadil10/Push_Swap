/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 23:18:16 by mfadil            #+#    #+#             */
/*   Updated: 2023/02/10 23:33:50 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_number(char *av)
{
	int	i;

	i = 0;
	if (ft_sign(av[i]) && av[i + 1])
		i++;
	while (av[i] && ft_isdigit(av[i]))
		i++;
	if (av[i] != '\0' && !ft_isdigit(av[i]))
		return (0);
	return (1);
}

static int	check_dup(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && strcmp_numbers(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// check the argument is zero (+0, -0, -00000, +0000,...)
int	check_is_zero(char *av)
{
	int	i;

	i = 0;
	if (ft_sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

// check if the arguments are all numbers and not duplicated
int	check_correct_input(char **av)
{
	int	i;
	int	nb_zero;

	nb_zero = 0;
	i = 1;
	while (av[i])
	{
		if (!check_number(av[i]))
			return (0);
		nb_zero += check_is_zero(av[i]);
		i++;
	}
	if (nb_zero > 1)
		return (0);
	if (check_dup(av))
		return (0);
	return (1);
}
