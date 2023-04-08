/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:15:11 by mfadil            #+#    #+#             */
/*   Updated: 2023/04/06 22:41:40 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

int	stack_sort_check(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	get_num(char *argv, t_stack **stack_a)
{
	char		**param;
	long int	n;
	int			i;

	param = ft_split(argv, ' ');
	i = 0;
	while (param[i] != '\0')
	{
		if (check_input(param[i]))
		{
			n = ft_atoi(param[i]);
			if (n > INT_MAX || n < INT_MIN)
				is_error(stack_a, NULL);
			add_to_bottom(stack_a, stack_new(n));
		}
		else
			is_error(NULL, NULL);
		free(param[i]);
		i++;
	}
	free(param);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;
	int		i;

	ft_norm(argv);
	stack_b = NULL;
	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		get_num(argv[i], &stack_a);
		i++;
	}
	if (check_dup(stack_a))
		is_error(&stack_a, NULL);
	size = sizeof_stack(stack_a);
	put_idx(stack_a, size + 1);
	push_swap(&stack_a, &stack_b, size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
