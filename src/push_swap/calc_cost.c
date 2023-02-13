/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akashets <akashets@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:44:49 by akashets          #+#    #+#             */
/*   Updated: 2023/02/12 14:58:20 by akashets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../../includes/push_swap.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	calculate_value(int a, int b)
{
	if ((a > 0 && b < 0) || (a < 0 && b > 0))
		return (ft_abs(a) + ft_abs(b));
	else if (ft_abs(a) > ft_abs(b))
		return (ft_abs(a));
	else
		return (ft_abs(b));
}

int	check_rotate_values(t_transf_price *prices, t_stack *a, t_stack *b)
{
	int		i;
	int		low;
	t_stack	*cur;

	i = 0;
	cur = b;
	low = 0;
	while (cur)
	{
		prices[i].moves[0] = ft_find_place(a, cur->value);
		prices[i].moves[1] = ft_check_lowest_rotations(b, cur->value);
		prices[i].value = \
			calculate_value(prices[i].moves[0], prices[i].moves[1]);
		if (prices[i].value < prices[low].value)
			low = i;
		i++;
		cur = cur->next;
	}
	return (low);
}

void	double_rot(t_transf_price *prices, \
	int index, t_stack **a, t_stack **b)
{
	while (prices[index].moves[0] > 0 && prices[index].moves[1] > 0)
	{
		prices[index].moves[0] -= 1;
		prices[index].moves[1] -= 1;
		rotate_rr(a, b, 1);
	}
	while (prices[index].moves[0] < 0 && prices[index].moves[1] < 0)
	{
		prices[index].moves[0] += 1;
		prices[index].moves[1] += 1;
		revrotate_rr(a, b, 1);
	}
}

void	single_rot(t_transf_price *prices, \
	int index, t_stack **a, t_stack **b)
{
	while (prices[index].moves[0] > 0)
	{
		prices[index].moves[0] -= 1;
		rotate_ra(a, 1);
	}
	while (prices[index].moves[1] > 0)
	{
		prices[index].moves[1] -= 1;
		rotate_rb(b, 1);
	}
	while (prices[index].moves[0] < 0)
	{
		prices[index].moves[0] += 1;
		revrotate_ra(a, 1);
	}
	while (prices[index].moves[1] < 0)
	{
		prices[index].moves[1] += 1;
		revrotate_rb(b, 1);
	}
}
