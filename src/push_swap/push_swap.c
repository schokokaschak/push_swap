/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akashets <akashets@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:24:05 by akashets          #+#    #+#             */
/*   Updated: 2023/02/12 14:59:12 by akashets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../../includes/push_swap.h"

void	push_to_b(t_stack **a, t_stack **b)
{
	t_stack	*buf;
	int		i;
	double	f;

	buf = *a;
	f = 0;
	while (buf)
	{
		f += ((double)buf->value / 1000);
		buf = buf->next;
	}
	i = (f * 1000) / get_size(a);
	while (get_size(a) > 3)
	{
		if ((*a)->value <= i)
		{
			push_pb(a, b, 1);
			rotate_rb(b, 1);
		}
		else
			push_pb(a, b, 1);
	}
}

void	push_back_sorted(t_stack **a, t_stack **b)
{
	t_transf_price	*prices;
	int				low;
	size_t			size;

	size = get_size(b);
	prices = (t_transf_price *)malloc(sizeof(t_transf_price) * size);
	while ((*b) != 0)
	{
		low = check_rotate_values(prices, *a, *b);
		double_rot(prices, low, a, b);
		single_rot(prices, low, a, b);
		push_pa(a, b, 1);
	}
	free(prices);
}

void	push_swap(t_stack **a, t_stack **b)
{
	int	rotates;

	push_pb(a, b, 1);
	push_pb(a, b, 1);
	push_to_b(a, b);
	if (!is_sorted(a))
		small_sort(a);
	push_back_sorted(a, b);
	rotates = ft_check_lowest_rotations(*a, get_min_value(a));
	while (rotates != 0)
	{
		if (rotates > 0)
		{
			rotate_ra(a, 1);
			rotates--;
		}
		else
		{
			revrotate_ra(a, 1);
			rotates++;
		}
	}
}

void	push_swap_check(t_stack **stack_a, t_stack **stack_b)
{
	if (get_size(stack_a) == 1)
		return ;
	else if (get_size(stack_a) == 2 && !is_sorted(stack_a))
		rotate_ra(stack_a, 1);
	else if (get_size(stack_a) < 4 && !is_sorted(stack_a))
		small_sort(stack_a);
	else if (get_size(stack_a) <= 5 && !is_sorted(stack_a))
		little_sort(stack_a, stack_b);
	else if (get_size(stack_a) > 5 && !is_sorted(stack_a))
		push_swap(stack_a, stack_b);
}
