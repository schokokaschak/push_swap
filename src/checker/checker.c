/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akashets <akashets@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:21:25 by akashets          #+#    #+#             */
/*   Updated: 2023/02/12 14:45:05 by akashets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/push_swap.h"

int	read_operations(t_stack **a, t_stack **b, char *op)
{
	if (!ft_strncmp(op, "sa\n", 4))
		swap_sa(a, 0);
	else if (!ft_strncmp(op, "sb\n", 4))
		swap_sb(b, 0);
	else if (!ft_strncmp(op, "ss\n", 4))
		swap_ss(a, b, 0);
	else if (!ft_strncmp(op, "pa\n", 4))
		push_pa(a, b, 0);
	else if (!ft_strncmp(op, "pb\n", 4))
		push_pb(a, b, 0);
	else if (!ft_strncmp(op, "ra\n", 4))
		rotate_ra(a, 0);
	else if (!ft_strncmp(op, "rb\n", 4))
		rotate_rb(b, 0);
	else if (!ft_strncmp(op, "rr\n", 4))
		rotate_rr(a, b, 0);
	else if (!ft_strncmp(op, "rra\n", 5))
		revrotate_ra(a, 0);
	else if (!ft_strncmp(op, "rrb\n", 5))
		revrotate_rb(b, 0);
	else if (!ft_strncmp(op, "rrr\n", 5))
		revrotate_rr(a, b, 0);
	else
		return (0);
	return (1);
}

void	print_result(t_stack *a, t_stack *b)
{
	if (is_sorted(&a) && !b)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

static t_stack	*ft_parse(int argc, char **argv)
{
	t_stack	*new;

	if (argc == 2 && !arg_is_number(argv[1]))
		new = parse_str(argv[1]);
	else
		new = parse_arr(argc, argv);
	return (new);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*op;

	a = ft_parse(argc, argv);
	op = get_next_line(0);
	while (op)
	{
		if (!read_operations(&a, &b, op))
		{
			free(op);
			list_clear(&a);
			msg_err("Error");
		}
		free(op);
		op = get_next_line(0);
	}
	free(op);
	print_result(a, b);
	list_clear(&a);
	list_clear(&b);
	return (0);
}
