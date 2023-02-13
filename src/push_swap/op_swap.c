/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akashets <akashets@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:07:52 by akashets          #+#    #+#             */
/*   Updated: 2023/02/02 11:03:50 by akashets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../../includes/push_swap.h"

static void	swap(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
}

void	swap_sa(t_stack **stack, int print)
{
	swap(*stack);
	if (print)
		ft_putendl_fd("sa", 1);
}

void	swap_sb(t_stack **stack, int print)
{
	swap(*stack);
	if (print)
		ft_putendl_fd("sb", 1);
}

void	swap_ss(t_stack **stack_a, t_stack **stack_b, int print)
{
	swap(*stack_a);
	swap(*stack_b);
	if (print)
		ft_putendl_fd("ss", 1);
}
