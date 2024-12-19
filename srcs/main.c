/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:17:21 by gueberso          #+#    #+#             */
/*   Updated: 2024/12/19 12:39:46 by gueberso         ###   ########.fr       */
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
	indexing(&stacks, 1);
	ft_printf("-------- Trié --------\n");
	for (int i = 0; i < stacks.tmp.size; i++)
		ft_printf("tmp[%d] : %d\n", i, stacks.tmp.addr[i]);
	ft_printf("\n\n");
	for (int i = 0; i < stacks.a.size; i++)
		ft_printf("a[%d] : %d\n", i, stacks.a.addr[i]);
	ft_printf("----------------------\n");
	free_stacks(&stacks);
	exit(SUCCESS);
}
