/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:41:40 by mfadil            #+#    #+#             */
/*   Updated: 2023/03/30 17:20:55 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_rrr(t_list **stack_a, t_list **stack_b, char *str)
{
	if (ft_strcmp(str, "rra\n"))
		check_rra(stack_a);
	else if (ft_strcmp(str, "rrb\n"))
		check_rrb(stack_b);
	else if (ft_strcmp(str, "rrr\n"))
		check_rrr(stack_a, stack_b);
	else
	{
		write (2, "Error\n", 6);
		exit(0);
	}
}

void	exec_sort(t_list **stack_a, t_list **stack_b, char *str)
{
	while (str != NULL)
	{
		if (ft_strcmp(str, "sa\n"))
			check_sa(stack_a);
		else if (ft_strcmp(str, "sb\n"))
			check_sb(stack_b);
		else if (ft_strcmp(str, "ss\n"))
			check_ss(stack_a, stack_b);
		else if (ft_strcmp(str, "pa\n"))
			check_pa(stack_b, stack_a);
		else if (ft_strcmp(str, "pb\n"))
			check_pb(stack_a, stack_b);
		else if (ft_strcmp(str, "ra\n"))
			check_ra(stack_a);
		else if (ft_strcmp(str, "rb\n"))
			check_rb(stack_b);
		else if (ft_strcmp(str, "rr\n"))
			check_rr(stack_a, stack_b);
		else
			exec_rrr(stack_a, stack_b, str);
		str = get_next_line(0);
	}
}

void	check_sort(t_list *a)
{
	while (a->next != NULL)
	{
		if (a->content > (a->next)->content)
		{
			write(1, "KO\n", 3);
			return ;
		}
		a = a->next;
	}
	write(1, "OK\n", 3);
	return ;
}

void	check_av(int ac, char **av, t_list **a)
{
	int		size;
	char	**ag;

	ag = NULL;
	size = 0;
	if (ac == 2)
	{
		ag = ft_split(av[1], ' ');
		while (ag[size] != NULL)
			size++;
		check_write_lst(a, size, ag, 0);
		free(ag);
	}
	else if (ac >= 3)
		check_write_lst(a, ac, av, 1);
}

int	main(int ac, char *av[])
{
	int		size;
	char	*str;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	size = 0;
	if (ac < 2)
		return (0);
	else
		check_av(ac, av, &a);
	str = get_next_line(0);
	exec_sort(&a, &b, str);
	check_sort(a);
	return (0);
}
