/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:17:21 by gueberso          #+#    #+#             */
/*   Updated: 2024/12/09 10:31:19 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int	*stack_a;
	int	*stack_b;
	int	*stack_tmp;

	stack_tmp = NULL;
	(void) stack_a;
	(void) stack_b;
	int stack_size = check_arg(ac, av, stack_tmp);
	for (int i = 0; i < stack_size; i++)
		ft_printf("%d\n", stack_tmp[i]);
	free(stack_tmp);
	return (0);
}
