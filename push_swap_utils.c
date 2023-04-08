/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:54:57 by mfadil            #+#    #+#             */
/*   Updated: 2023/04/07 22:26:32 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	is_error(t_stack **a, t_stack **b)
{
	if (a == NULL || *a != NULL)
		free_stack(a);
	if (b == NULL || *b != NULL)
		free_stack(b);
	write(2, "Error\n", 6);
	exit (1);
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

long int	ft_atoi(const char *str)
{
	int				i;
	long int		result;
	int				negatif;

	i = 0;
	negatif = 1;
	result = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r' ))
		str++;
	if (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			negatif *= -1;
		str++;
	}
	while (ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - 48);
	if (result > 9223372036854775807 && negatif == 1)
		return (-1);
	else if (result - 1 > 9223372036854775807 && negatif == -1)
		return (0);
	return (result * negatif);
}
