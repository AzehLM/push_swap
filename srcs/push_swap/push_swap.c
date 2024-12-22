/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:17:21 by gueberso          #+#    #+#             */
/*   Updated: 2024/12/22 15:48:54 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
