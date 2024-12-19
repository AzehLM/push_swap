/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:17:36 by gueberso          #+#    #+#             */
/*   Updated: 2024/12/19 12:32:51 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_av1(char **split, int *stack, size_t size)
{
	size_t	i;

	if (split)
	{
		i = 0;
		while (i < size && split[i])
			free(split[i++]);
		free(split);
	}
	if (stack)
		free(stack);
}

static void	parse_string_err_management(int size, char **spt, t_stacks *stacks)
{
	int	i;

	if (size == 0)
	{
		free(spt);
		exit_with_error(ERR_EMPTY_STRING);
	}
	i = 0;
	while (i < size)
	{
		if (!is_strdigit(spt[i]))
		{
			free_av1(spt, stacks->tmp.addr, size);
			exit_with_error(ERR_NO_NUMERIC);
		}
		if (!check_out_of_range(spt[i]))
		{
			free_av1(spt, stacks->tmp.addr, size);
			exit_with_error(ERR_OUT_OF_RANGE);
		}
		stacks->tmp.addr[i] = ft_atoi(spt[i]);
		i++;
	}
	stacks->tmp.size = size;
}

int	parse_string(const char *str, t_stacks *stacks)
{
	char	**split;
	int		size;

	split = ft_split(str, ' ');
	if (!split)
		exit_with_error(ERR_MALLOC);
	size = 0;
	while (split[size])
		size++;
	parse_string_err_management(size, split, stacks);
	//sort_tmp(stacks);
	if (!check_duplicates(stacks->tmp.addr, stacks->tmp.size))
	{
		free_stacks(stacks);
		exit_with_error(ERR_DUPLICATE);
	}
	free_av1(split, NULL, size);
	return (0);
}
