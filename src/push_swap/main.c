/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akashets <akashets@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 10:57:47 by akashets          #+#    #+#             */
/*   Updated: 2023/02/12 15:31:35 by akashets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	if (argc < 2 || (argc == 2 && argv[1][0] == 0))
		msg_err("Error");
	if (argc == 2 && !arg_is_number(argv[1]))
		a = parse_str(argv[1]);
	else
		a = parse_arr(argc, argv);
	push_swap_check(&a, &b);
	list_clear(&a);
	return (0);
}
