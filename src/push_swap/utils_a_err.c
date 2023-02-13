/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akashets <akashets@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:55:15 by akashets          #+#    #+#             */
/*   Updated: 2023/02/02 11:43:48 by akashets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../../includes/push_swap.h"

void	msg_err(const char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}

void	ft_putendl_fd(char const *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

void	list_clear(t_stack **a)
{
	t_stack	*cur;
	t_stack	*next;

	cur = *a;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	*a = NULL;
}
