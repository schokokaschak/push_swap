/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akashets <akashets@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:38:48 by akashets          #+#    #+#             */
/*   Updated: 2023/02/12 14:52:36 by akashets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../../includes/push_swap.h"

void	small_sort(t_stack **s)
{
	if ((*s)->value < (*s)->next->value && \
		(*s)->value > (*s)->next->next->value)
		revrotate_ra(s, 1);
	else if ((*s)->value < (*s)->next->value && \
		(*s)->value < (*s)->next->next->value)
	{
		revrotate_ra(s, 1);
		swap_sa(s, 1);
	}
	else if ((*s)->value > (*s)->next->value && \
		(*s)->value < (*s)->next->next->value)
		swap_sa(s, 1);
	else if ((*s)->value > (*s)->next->value && \
		(*s)->next->value > (*s)->next->next->value)
	{
		rotate_ra(s, 1);
		swap_sa(s, 1);
	}
	else if ((*s)->value > (*s)->next->value && \
		(*s)->next->value < (*s)->next->next->value)
		rotate_ra(s, 1);
}

void	little_sort(t_stack **a, t_stack **b)
{
	if (get_size(a) == 5)
		push_pb(a, b, 1);
	push_pb(a, b, 1);
	if (!is_sorted(a))
		small_sort(a);
	if (get_size(b) == 2 && !is_sorted(b))
		swap_sb(b, 1);
	while ((*b) != NULL)
	{	
		if ((*b)->value < (*a)->value)
			push_pa(a, b, 1);
		else if ((*b)->value > get_max_value(a))
		{
			while ((*a)->value != get_min_value(a))
				rotate_ra(a, 1);
			push_pa(a, b, 1);
		}
		else
			rotate_ra(a, 1);
	}
	while (!is_sorted(a))
		rotate_ra(a, 1);
}
