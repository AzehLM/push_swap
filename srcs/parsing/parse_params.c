/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:07:09 by gueberso          #+#    #+#             */
/*   Updated: 2024/12/19 18:20:21 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	parse_params_err_management(int i, char **av, t_stacks *stacks)
{
	while (av[i])
	{
		if (!is_strdigit(av[i]))
		{
			free_stacks(stacks);
			exit_with_error(ERR_NO_NUMERIC);
		}
		if (!check_out_of_range(av[i]))
		{
			free_stacks(stacks);
			exit_with_error(ERR_OUT_OF_RANGE);
		}
		stacks->tmp.addr[i - 1] = ft_atoi(av[i]);
		i++;
	}
	stacks->tmp.size = i - 1;
}

int	parse_params(int ac, char **av, t_stacks *stacks)
{
	parse_params_err_management(1, av, stacks);
	if (!check_duplicates(stacks->tmp.addr, ac - 1))
	{
		free_stacks(stacks);
		exit_with_error(ERR_DUPLICATE);
	}
	return (0);
}
