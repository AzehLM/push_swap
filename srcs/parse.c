/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:17:36 by gueberso          #+#    #+#             */
/*   Updated: 2024/12/08 16:48:43 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void	free_av2(char **split, int *stack_tmp, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	free(stack_tmp);
}

int	*parse_string(const char *str, int **stack_tmp)
{
	char	**split;
	size_t	i;
	size_t	size;
	
	split = ft_split(str, ' ');
	if (!split)
		exit_with_error(ERR_MALLOC);
	size = 0;
	while (split[size])
		split++;
	*stack_tmp = malloc(sizeof(int) * size);
	if (!(*stack_tmp))
		exit_with_error(ERR_MALLOC);
	i = 0;
	while (i < size)
	{
		if (!is_strdigit(split[i]))
		{
			free_all(split, stack_tmp, size);
			exit_with_error(ERR_NO_NUMERIC);
		}
		(*stack_tmp)[i] = ft_atoi(split[i]);
		if (str[i] )
	}
	return (0);
}
