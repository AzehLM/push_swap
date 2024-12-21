/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:53:40 by gueberso          #+#    #+#             */
/*   Updated: 2024/12/21 22:39:01 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_with_error(t_exit_code error_code)
{
	if (error_code == ERR_NO_PARAMETERS)
		exit(ERR_NO_PARAMETERS);
	write(STDERR_FILENO, "Error\n", 6);
	exit(error_code);
}

int	check_arg(int ac, char **av, t_stacks *stacks)
{
	if (ac < 2)
		exit_with_error(ERR_NO_PARAMETERS);
	else if (ac == 2 && parse_string(av[1], stacks) == 0)
		return (0);
	else if (ac > 2 && parse_params(ac, av, stacks) == 0)
		return (0);
	return (0);
}
