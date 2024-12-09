/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:17:36 by gueberso          #+#    #+#             */
/*   Updated: 2024/12/09 16:48:41 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	free_av1(char **split, int *stack_tmp, size_t size)
// {
// 	size_t	i;

// 	if (split)
// 	{
// 		i = 0;
// 		while (i < size && split[i])
// 			free(split[i++]);
// 		free(split);
// 	}
// 	if (stack_tmp)
// 		free(stack_tmp);
// }

// static int	is_strdigit(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	if (str[0] == '-' || str[0] == '+')
// 		i++;
// 	while (str[i])
// 	{
// 		if (!ft_isdigit(str[i]))
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// int	check_out_of_range(const char *str)
// {
// 	long long	res;
// 	int			sign;
// 	int			i;

// 	i = 0;
// 	res = 0;
// 	sign = 1;
// 	if (str[i] == '-' || str[i] == '+')
// 		if (str[i++] == '-')
// 			sign = -1;
// 	while (str[i] && ft_isdigit(str[i]))
// 	{
// 		res = res * 10 + (str[i] - '0');
// 		if (sign == 1 && res > INT_MAX)
// 			return (0);
// 		if (sign == -1 && (res * -1) < INT_MIN)
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// static void	parse_string_error_management(int size, char **spt, int **stack_tmp)
// {
// 	int	i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		if (!is_strdigit(spt[i]))
// 		{
// 			free_av1(spt, *stack_tmp, size);
// 			exit_with_error(ERR_NO_NUMERIC);
// 		}
// 		if (!check_out_of_range(spt[i]))
// 		{
// 			free_av1(spt, *stack_tmp, size);
// 			exit_with_error(ERR_OUT_OF_RANGE);
// 		}
// 		(*stack_tmp)[i] = ft_atoi(spt[i]);
// 		i++;
// 	}
// }

// int	parse_string(const char *str, int **stack_tmp)
// {
// 	char	**split;
// 	int		size;

// 	split = ft_split(str, ' ');
// 	if (!split)
// 		exit_with_error(ERR_MALLOC);
// 	size = 0;
// 	while (split[size])
// 		size++;
// 	*stack_tmp = malloc(sizeof(int) * size);
// 	if (!(*stack_tmp))
// 	{
// 		free_av1(split, *stack_tmp, size);
// 		exit_with_error(ERR_MALLOC);
// 	}
// 	parse_string_error_management(size, split, stack_tmp);
// 	sort_tmp(*stack_tmp, size);
// 	if (!check_duplicates(*stack_tmp, size))
// 	{
// 		free_av1(split, *stack_tmp, size);
// 		exit_with_error(ERR_DUPLICATE);
// 	}
// 	free_av1(split, NULL, size);
// 	return (0);
// }

static void	free_av1(char **split, int *stack_tmp, size_t size)
{
	size_t	i;

	if (split)
	{
		i = 0;
		while (i < size && split[i])
			free(split[i++]);
		free(split);
	}
	if (stack_tmp)
		free(stack_tmp);
}

static void	parse_string_error_management(int size, char **spt, int **stack_tmp)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!is_strdigit(spt[i]))
		{
			free_av1(spt, *stack_tmp, size);
			exit_with_error(ERR_NO_NUMERIC);
		}
		if (!check_out_of_range(spt[i]))
		{
			free_av1(spt, *stack_tmp, size);
			exit_with_error(ERR_OUT_OF_RANGE);
		}
		(*stack_tmp)[i] = ft_atoi(spt[i]);
		i++;
	}
}

int	parse_string(const char *str, int **stack_tmp)
{
	char	**split;
	int		size;

	split = ft_split(str, ' ');
	if (!split)
		exit_with_error(ERR_MALLOC);
	size = 0;
	while (split[size])
		size++;
	*stack_tmp = malloc(sizeof(int) * size);
	if (!(*stack_tmp))
	{
		free_av1(split, *stack_tmp, size);
		exit_with_error(ERR_MALLOC);
	}
	parse_string_error_management(size, split, stack_tmp);
	sort_tmp(*stack_tmp, size);
	if (!check_duplicates(*stack_tmp, size))
	{
		free_av1(split, *stack_tmp, size);
		exit_with_error(ERR_DUPLICATE);
	}
	free_av1(split, NULL, size);
	return (0);
}
