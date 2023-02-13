/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akashets <akashets@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:23:42 by akashets          #+#    #+#             */
/*   Updated: 2023/02/04 22:00:51 by akashets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../../includes/push_swap.h"

t_stack	*stack_new(int nb)
{
	t_stack	*new;

	new = malloc(sizeof(*new));
	if (!new)
		msg_err("Error");
	new->value = nb;
	new->next = NULL;
	return (new);
}

void	add_stack_bot(t_stack **stack, t_stack *new)
{
	t_stack	*tail;

	if (!new)
		msg_err("Error");
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tail = get_bot(*stack);
	tail->next = new;
}

t_stack	*get_bot(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*get_bbot(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}
