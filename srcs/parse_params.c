/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:07:09 by gueberso          #+#    #+#             */
/*   Updated: 2024/12/09 17:08:38 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_params(int ac, char **av, int **stack_tmp)
{
	int		i;

	*stack_tmp = malloc(sizeof(int) * (ac - 1));
	if (!(*stack_tmp))
		exit_with_error(ERR_MALLOC);
	i = 1;
	while (av[i])
	{
		if (!is_strdigit(av[i]))
			exit_with_error(ERR_NO_NUMERIC);
		if (!check_out_of_range(av[i]))
			exit_with_error(ERR_OUT_OF_RANGE);
		(*stack_tmp)[i - 1] = ft_atoi(av[i]);
		i++;
	}
	sort_tmp(*stack_tmp, ac - 1);
	if (!check_duplicates(*stack_tmp, ac - 1))
	{
		free(*stack_tmp);
		exit_with_error(ERR_DUPLICATE);
	}
	return (0);
}
