/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:17:21 by gueberso          #+#    #+#             */
/*   Updated: 2024/12/18 14:42:59 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int	*stack_a;
	int	*stack_b;
	int	*stack_tmp;
	
	stack_tmp = NULL;
	(void) stack_b;
	(void) stack_a;
	check_arg(ac, av, &stack_tmp);
	stack_a = malloc(sizeof(int) * get_stack_len(stack_tmp));
	indexing(stack_tmp, stack_a, get_stack_len(stack_tmp));
	int i = 0;
	ft_printf("-------- Trié --------\n");
	while (i < get_stack_len(stack_tmp))
	{
		ft_printf("stack_tmp[%d] : %d\n", i, stack_tmp[i]);
		i++;
	}
	i = 0;
	ft_printf("\n\n");
	while (i < get_stack_len(stack_tmp))
	{
		ft_printf("stack_a[%d] : %d\n", i, stack_a[i]);
		i++;
	}
	ft_printf("----------------------\n");
	free(stack_tmp); // replace by free_stacks --> functions to free every stacks before exiting program.
	exit(SUCCESS);
	return (0);
}
