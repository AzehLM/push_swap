/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:53:40 by gueberso          #+#    #+#             */
/*   Updated: 2024/12/08 18:29:55 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_with_error(t_error error)
{
	if (error == ERR_NO_PARAMETERS)
		exit(ERR_NO_PARAMETERS);
	else
		write(2, "Error\n", 6);
	if (error == ERR_NO_NUMERIC)
		exit(ERR_NO_NUMERIC);
	else if (error == ERR_OUT_OF_RANGE)
		exit(ERR_OUT_OF_RANGE);
	else if (error == ERR_DUPLICATE)
		exit(ERR_DUPLICATE);
	else
		exit(ERR_UNKNOWN);
}

int	check_arg(int ac, char **av, int *stack_tmp)
{
	if (ac < 2)
		exit_with_error(ERR_NO_PARAMETERS);
	ft_printf("%s\n", av[1]);
	if (ac == 2 && parse_string(av[1], &stack_tmp) == 1)
		exit_with_error(ERR_NO_NUMERIC);
	//exit_with_error(25);
	return (0);
}
