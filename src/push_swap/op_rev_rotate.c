/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akashets <akashets@student.42wolfsbur      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:03:54 by akashets          #+#    #+#             */
/*   Updated: 2023/01/29 13:18:32 by akashets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../../includes/push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*bot;
	t_stack	*bbot;

	bot = get_bot(*stack);
	bbot = get_bbot(*stack);
	tmp = *stack;
	*stack = bot;
	(*stack)->next = tmp;
	bbot->next = NULL;
}

void	revrotate_ra(t_stack **stack_a, int print)
{
	rev_rotate(stack_a);
	if (print)
		ft_putendl_fd("rra", 1);
}

void	revrotate_rb(t_stack **stack_b, int print)
{
	rev_rotate(stack_b);
	if (print)
		ft_putendl_fd("rrb", 1);
}

void	revrotate_rr(t_stack **stack_a, t_stack **stack_b, int print)
{
	rev_rotate(stack_b);
	rev_rotate(stack_a);
	if (print)
		ft_putendl_fd("rrr", 1);
}
