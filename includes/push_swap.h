/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akashets <akashets@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 10:59:24 by akashets          #+#    #+#             */
/*   Updated: 2023/02/12 14:57:52 by akashets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define  PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}				t_stack;

typedef struct s_transf_price
{
	int	moves[2];
	int	value;
}				t_transf_price;

void		swap_sa(t_stack **stack, int print);
void		swap_sb(t_stack **stack, int print);
void		swap_ss(t_stack **stack_a, t_stack **stack_b, int print);
void		push_pa(t_stack **stack_a, t_stack **stack_b, int print);
void		push_pb(t_stack **stack_a, t_stack **stack_b, int print);
void		rotate_ra(t_stack **stack_a, int print);
void		rotate_rb(t_stack **stack_b, int print);
void		rotate_rr(t_stack **stack_a, t_stack **stack_b, int print);
void		revrotate_ra(t_stack **stack_a, int print);
void		revrotate_rb(t_stack **stack_b, int print);
void		revrotate_rr(t_stack **stack_a, t_stack **stack_b, int print);
void		add_stack_bot(t_stack **stack, t_stack *new);
void		msg_err(const char *str);
void		ft_putendl_fd(char const *s, int fd);
void		push_swap_check(t_stack **stack_a, t_stack **stack_b);
void		small_sort(t_stack **s);
void		little_sort(t_stack **a, t_stack **b);
void		push_swap(t_stack **a, t_stack **b);
void		push_to_b(t_stack **a, t_stack **b);
void		double_rot(t_transf_price *p, int i, t_stack **a, t_stack **b);
void		single_rot(t_transf_price *p, int i, t_stack **a, t_stack **b);
void		push_sorted(t_stack **a, t_stack **b);
void		push_back_sorted(t_stack **a, t_stack **b);
void		list_clear(t_stack **a);
void		ft_free_split(char **numbers);
long int	ft_atoi2(const char *str);
size_t		get_size(t_stack **stack);
int			ft_input_check(char **argv);
int			nbstr_cmp(const char *s1, const char *s2);
int			is_sign(char c);
int			is_digit(char c);
int			arg_is_number(char *arg);
int			is_sorted(t_stack **stack);
int			get_max_value(t_stack **s);
int			get_min_value(t_stack **s);
int			ft_check_lowest_rotations(t_stack *a, int value);
int			check_rotate_values(t_transf_price *prices, t_stack *a, t_stack *b);
int			ft_find_place(t_stack *a, int value);
t_stack		*parse_arr(int argc, char **argv);
t_stack		*parse_str(char *str);
t_stack		*get_bbot(t_stack *stack);
t_stack		*stack_new(int nb);
t_stack		*get_bot(t_stack *stack);

#endif
