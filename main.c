/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:15:11 by mfadil            #+#    #+#             */
/*   Updated: 2023/03/26 21:34:39 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check if the stack is sorted
//int	check_sort(t_stack *stack)
//{
//	while (stack->next != NULL)
//	{
//		if (stack->data > stack->next->data)
//			return (0);
//		stack = stack->next;
//	}
//	return (1);
//}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

//void	get_num(char *argv, t_stack **stack_a)
//{
//	long int	n;
//	int			i;
//	char		**param;

//	param = ft_split(argv, ' ');
//	i = 0;
//	while (param[i])
//	{
//		if (input_is_correct(param[i]))
//		{
//			n = ft_atoi(param[i]);
//			if (n > INT_MAX || n < INT_MIN)
//				error(stack_a, NULL);
//			add_bottom_of_stack(stack_a, new_stack(n));
//		}
//		else
//			error(NULL, NULL);
//		free(param[i]);
//		i++;
//	}
//	free(param);
//}

//static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
//{
//	if (stack_size == 2 && !check_sort(*stack_a))
//		swap_a(stack_a);
//	else if (stack_size == 3)
//		mini_sort(stack_a);
//	else if (stack_size > 3 && !check_sort(*stack_a))
//		ft_sort(stack_a, stack_b);
//}

//int	main(int argc, char **argv)
//{
//	int		i;
//	int		size;
//	t_stack	*stack_a;
//	t_stack	*stack_b;

//	i = 1;
//	stack_a = NULL;
//	stack_b = NULL;
//	while (i < argc)
//	{
//		get_num(argv[i], &stack_a);
//		i++;
//	}
//	if (is_duplicate(stack_a))
//		error(&stack_a, NULL);
//	size = sizeof_stack(stack_a);
//	get_index(stack_a, size + 1);
//	push_swap(&stack_a, &stack_b, size);
//	free_stack(&stack_a);
//	free_stack(&stack_b);
//	return (0);
//}

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		do_sa(stack_a);
	else if (stack_size == 3)
		sort_three(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

void	get_numbers(char *av, t_stack **stack_a)
{
	char		**param;
	long int	n;
	int			i;

	param = ft_split(av, ' ');
	i = 0;
	while (param[i] != '\0')
	{
		if (check_input(param[i]))
		{
			n = ft_atoi(param[i]);
			if (n > INT_MAX || n < INT_MIN)
				error_exit(stack_a, NULL);
			stack_add(stack_a, stack_new(n));
		}
		else
			error_exit(NULL, NULL);
		free(param[i]);
		i++;
	}
	free(param);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
	int		i;

	ft_norm(av);
	i = 1;
	stack_b = NULL;
	stack_a = NULL;
	while (i < ac)
	{
		get_numbers(av[i], &stack_a);
		i++;
	}
	if (check_dup(stack_a))
		error_exit(&stack_a, NULL);
	stack_size = get_stack_size(stack_a);
	get_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
