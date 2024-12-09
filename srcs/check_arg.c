/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:53:40 by gueberso          #+#    #+#             */
/*   Updated: 2024/12/09 10:46:13 by gueberso         ###   ########.fr       */
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

int	check_arg(int ac, char **av, int **stack_tmp)
{
	if (ac < 2)
		exit_with_error(ERR_NO_PARAMETERS);
	ft_printf("%s\n", av[1]);
	if (ac == 2 && parse_string(av[1], stack_tmp) == 0)
		ft_printf("success\n");
	// int	i = 0;
	// ft_printf("---\n");
	// while (*stack_tmp)
	// 	ft_printf("stack_tmp[%d] : %d\n", i, *stack_tmp++);
	// ft_printf("---\n");
	return (0);
}
