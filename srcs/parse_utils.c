/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:25:00 by gueberso          #+#    #+#             */
/*   Updated: 2024/12/19 12:36:24 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	is_strdigit(const char *str)
{
	size_t	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_out_of_range(const char *str)
{
	long long	res;
	int			sign;
	int			i;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] && ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		if (sign == 1 && res > INT_MAX)
			return (0);
		if (sign == -1 && (res * -1) < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(int *stack, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack[i] == stack[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	get_stack_len(int *stack_tmp)
{
	int	len_stack;

	len_stack = 0;
	while (stack_tmp[len_stack] != '\0')
		len_stack++;
	return (len_stack);
}

int	count_numbers(const char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str && str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i])
		{
			if (str[i] == '-' || str[i] == '+')
				i++;
			if (!str[i] || !ft_isdigit(str[i]))
				exit_with_error(ERR_NO_NUMERIC);
			count++;
			while (str[i] && ft_isdigit(str[i]))
				i++;
			if (str[i] && str[i] != ' ')
				exit_with_error(ERR_NO_NUMERIC);
		}
	}
	return (count);
}
