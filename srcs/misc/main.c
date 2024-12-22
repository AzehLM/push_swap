/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:17:21 by gueberso          #+#    #+#             */
/*   Updated: 2024/12/22 13:22:07 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stacks *stacks)
{
	int	i;

	if (stacks->a.size <= 1)
		return (1);
	i = 0;
	while (i < stacks->a.size - 1)
	{
		if (stacks->a.addr[i] > stacks->a.addr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stacks	stacks;
	int			size;

	if (ac < 2)
		exit_with_error(ERR_NO_PARAMETERS);
	if (ac == 2)
		size = count_numbers(av[1]);
	else
		size = ac - 1;
	init_stacks(&stacks, size);
	check_arg(ac, av, &stacks);
	indexing(&stacks, -1, 1);
	if (!is_sorted(&stacks))
		sort_hmoon(&stacks);
	free_stacks(&stacks);
	exit(SUCCESS);
}
