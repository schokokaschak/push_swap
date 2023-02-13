/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akashets <akashets@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:42:23 by akashets          #+#    #+#             */
/*   Updated: 2023/02/03 11:40:04 by akashets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../../includes/push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*bot;

	tmp = *stack;
	*stack = (*stack)->next;
	bot = get_bot(*stack);
	tmp->next = NULL;
	bot->next = tmp;
}

void	rotate_ra(t_stack **stack_a, int print)
{
	rotate(stack_a);
	if (print)
		ft_putendl_fd("ra", 1);
}

void	rotate_rb(t_stack **stack_b, int print)
{
	rotate(stack_b);
	if (print)
		ft_putendl_fd("rb", 1);
}

void	rotate_rr(t_stack **stack_a, t_stack **stack_b, int print)
{
	rotate(stack_a);
	rotate(stack_b);
	if (print)
		ft_putendl_fd("rr", 1);
}
