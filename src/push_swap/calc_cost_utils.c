/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cost_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akashets <akashets@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:49:16 by akashets          #+#    #+#             */
/*   Updated: 2023/02/06 17:41:17 by akashets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../../includes/push_swap.h"

int	ft_check_lowest_rotations(t_stack *a, int value)
{
	t_stack	*cur;
	size_t	i;

	cur = a;
	i = 0;
	while (cur && cur->value != value)
	{
		cur = cur->next;
		i++;
	}
	if (get_size(&a) - i < i)
		return (i - get_size(&a));
	return (i);
}

int	ft_find_place(t_stack *a, int value)
{
	t_stack	*cur;
	int		low;
	int		is_max;

	is_max = 1;
	cur = a;
	low = INT_MAX;
	while (cur)
	{
		if (cur->value > value && cur->value <= low)
		{
			is_max = 0;
			low = cur->value;
		}
		cur = cur ->next;
	}
	if (is_max)
		low = get_min_value(&a);
	return (ft_check_lowest_rotations(a, low));
}
