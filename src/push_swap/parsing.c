/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akashets <akashets@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:32:50 by akashets          #+#    #+#             */
/*   Updated: 2023/02/12 14:54:01 by akashets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../../includes/push_swap.h"

t_stack	*parse_arr(int argc, char **argv)
{
	t_stack		*new;
	int			i;
	long int	nb;

	i = 1;
	if (!ft_input_check(argv + 1))
		msg_err("Error");
	while (i < argc)
	{
		nb = ft_atoi2(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			msg_err("Error");
		else if (i == 1)
			new = stack_new((int)nb);
		else
			add_stack_bot(&new, stack_new((int)nb));
		i++;
	}
	return (new);
}

t_stack	*parse_str(char *str)
{
	t_stack		*new;
	char		**numbers;
	int			i;
	long int	nb;

	numbers = ft_split(str, ' ');
	if (!ft_input_check(numbers))
		msg_err("Error");
	i = 0;
	while (numbers[i])
	{
		nb = ft_atoi2(numbers[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			msg_err("Error");
		if (i == 0)
			new = stack_new((int)nb);
		else
			add_stack_bot(&new, stack_new((int)nb));
		i++;
	}
	ft_free_split(numbers);
	return (new);
}

long int	ft_atoi2(const char *str)
{
	long int	nb;
	int			isneg;
	int			i;

	nb = 0;
	isneg = 1;
	i = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (is_digit(str[i]))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * isneg);
}

void	ft_free_split(char **numbers)
{
	size_t	i;

	i = 0;
	while (numbers[i])
	{
		free(numbers[i]);
		i++;
	}
	free(numbers);
}
