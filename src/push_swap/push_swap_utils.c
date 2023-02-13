/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akashets <akashets@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:32:10 by akashets          #+#    #+#             */
/*   Updated: 2023/02/03 11:22:56 by akashets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../../includes/push_swap.h"

size_t	get_size(t_stack **stack)
{
	size_t	i;
	t_stack	*new;

	i = 1;
	new = *stack;
	if (stack == NULL)
		return (0);
	while (new->next != NULL)
	{
		i++;
		new = new->next;
	}
	return (i);
}

int	is_sorted(t_stack **stack)
{
	t_stack	*new;

	new = *stack;
	while (new->next != NULL)
	{
		if (new->value > new->next->value)
			return (0);
		new = new->next;
	}
	return (1);
}

int	get_max_value(t_stack **s)
{
	int		i;
	t_stack	*buf;

	buf = *s;
	if (s == NULL)
		return (0);
	i = buf->value;
	while (buf->next != NULL)
	{
		if (i < buf->next->value)
			i = buf->next->value;
		buf = buf->next;
	}
	return (i);
}

int	get_min_value(t_stack **s)
{
	int		i;
	t_stack	*buf;

	buf = *s;
	if (s == NULL)
		return (0);
	i = buf->value;
	while (buf->next != NULL)
	{
		if (i > buf->next->value)
			i = buf->next->value;
		buf = buf->next;
	}
	return (i);
}
