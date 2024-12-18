/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 00:20:44 by gueberso          #+#    #+#             */
/*   Updated: 2024/12/18 14:46:56 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(int *stack_tmp, int *stack_a, int size)
{
	static int	i = -1;
	static int	j = 0;
	int			*indexing_stack;
	int			rank;

	indexing_stack = malloc(sizeof(int) * size);
	if (!indexing_stack)
		exit_with_error(ERR_MALLOC);
	while (++i < size)
		indexing_stack[i] = stack_tmp[i];
	i = 0;
	while (i < size)
	{
		rank = 1;
		j = 0;
		while (j < size)
		{
			if (indexing_stack[j] < indexing_stack[i])
				rank++;
			j++;
		}
		stack_a[i] = rank;
		i++;
	}
	free(indexing_stack);
}
