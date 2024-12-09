/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:53:40 by gueberso          #+#    #+#             */
/*   Updated: 2024/12/09 10:16:16 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_with_error(t_error error_code)
{
	if (error_code == ERR_NO_PARAMETERS)
		exit(ERR_NO_PARAMETERS);
	else
		write(2, "Error\n", 6);
	exit(error_code);
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
