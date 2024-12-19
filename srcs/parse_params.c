/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:07:09 by gueberso          #+#    #+#             */
/*   Updated: 2024/12/19 13:45:23 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	parse_params_err_management(int i, char **av, int **stack_tmp)
// {
// 	while (av[i])
// 	{
// 		if (!is_strdigit(av[i]))
// 		{
// 			free(*stack_tmp);
// 			*stack_tmp = NULL;
// 			exit_with_error(ERR_NO_NUMERIC);
// 		}
// 		if (!check_out_of_range(av[i]))
// 		{
// 			free(*stack_tmp);
// 			*stack_tmp = NULL;
// 			exit_with_error(ERR_OUT_OF_RANGE);
// 		}
// 		(*stack_tmp)[i - 1] = ft_atoi(av[i]);
// 		i++;
// 	}
// }

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
		stacks->tmp.addr[i] = ft_atoi(av[i]);
		i++;
	}
	stacks->tmp.size = i;
	ft_printf("%d\n", stacks->tmp.size);
}

int	parse_params(int ac, char **av, t_stacks *stacks)
{
	parse_params_err_management(1, av, stacks);
	if (!check_duplicates(stacks->tmp.addr, ac))
	{
		free_stacks(stacks);
		exit_with_error(ERR_DUPLICATE);
	}
	return (0);
}

// int	parse_params(int ac, char **av, int **stack_tmp)
// {

// 	if (!(*stack_tmp))
// 		exit_with_error(ERR_MALLOC);
// 	parse_params_err_management(1, av, stack_tmp);
// 	//sort_tmp(*stack_tmp, ac - 1);
// 	if (!check_duplicates(*stack_tmp, ac - 1))
// 	{
// 		free(*stack_tmp);
// 		*stack_tmp = NULL;
// 		exit_with_error(ERR_DUPLICATE);
// 	}
// 	return (0);
// }
