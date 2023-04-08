/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:29:01 by mfadil            #+#    #+#             */
/*   Updated: 2023/04/08 00:54:31 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stddef.h>

typedef struct s_stack
{
	int				data;
	int				index;
	int				position;
	int				tar_position;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

long		check_input(char *av);
void		is_error(t_stack **stack_a, t_stack **stack_b);
void		free_stack(t_stack **stack);
long int	ft_atoi(const char *str);
void		put_idx(t_stack *stack_a, int size);
t_stack		*stack_new(int value);
void		add_to_bottom(t_stack **stack, t_stack *new);
t_stack		*get_last_element(t_stack *stack);
t_stack		*get_before_last(t_stack *stack);
int			sizeof_stack(t_stack	*stack);
int			stack_sort_check(t_stack *stack);
void		mini_sort(t_stack **stack);
void		push_to_a(t_stack **stack_a, t_stack **stack_b);
void		push_to_b(t_stack **stack_a, t_stack **stack_b);
void		swap_a(t_stack **stack_a);
void		swap_b(t_stack **stack_b);
void		swap_all(t_stack **stack_a, t_stack **stack_b);
void		rotate_a(t_stack **stack_a);
void		rotate_b(t_stack **stack_b);
void		rotate_all(t_stack **stack_a, t_stack **stack_b);
void		reverse_rotate_a(t_stack **stack_a);
void		reverse_rotate_b(t_stack **stack_b);
void		reverse_rotate_all(t_stack **stack_a, t_stack **stack_b);
void		ft_sort(t_stack **a, t_stack **b);
void		push_swap(t_stack **a, t_stack **b, int size);
void		get_target_position(t_stack **stack_a, t_stack **stack_b);
void		get_cost(t_stack **stack_a, t_stack **stack_b);
void		reduce_moves(t_stack **stack_a, t_stack **stack_b);
void		do_best_move(t_stack **a, t_stack **b, int cost_a, int cost_b);
int			low_index_position(t_stack **stack);
char		**ft_split(char const *s, char c);
int			stack_sort_check(t_stack *stack);
int			check_dup(t_stack *stack);
size_t		ft_strlen(const char *s);
void		ft_putstr(char *str);
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *b, int c, size_t len);
void		ft_norm(char **av);

// checker stuffs

void		check_pa(t_list **b, t_list **a);
void		check_pb(t_list **a, t_list **b);
void		check_sa(t_list **a);
void		check_sb(t_list **b);
void		check_ss(t_list **a, t_list **b);
void		check_ra(t_list **a);
void		check_rb(t_list **b);
void		check_rr(t_list **a, t_list **b);
void		check_rra(t_list **a);
void		check_rrb(t_list **b);
void		check_rrr(t_list **a, t_list **b);

void		lst_check_c(t_list *a, int check);
void		lst_order(t_list **a);
void		check_lst_inverted(t_list **a);
void		check_write_lst(t_list **a, int ac, char **av, int i);

t_list		*ft_lstnew(int content);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			ft_strcmp(char *s1, char *s2);

#endif