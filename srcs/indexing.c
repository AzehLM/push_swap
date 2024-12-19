/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 00:20:44 by gueberso          #+#    #+#             */
/*   Updated: 2024/12/19 12:39:53 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_stacks *stacks, int rank)
{
	static int	i = -1;
	static int	j = 0;
	int			*indexing_stack;

	indexing_stack = malloc(sizeof(int) * stacks->tmp.size);
	if (!indexing_stack)
	{
		free_stacks(stacks);
		exit_with_error(ERR_MALLOC);
	}
	while (++i < stacks->tmp.size)
		indexing_stack[i] = stacks->tmp.addr[i];
	i = -1;
	while (++i < stacks->tmp.size)
	{
		j = 0;
		while (j < stacks->tmp.size)
		{
			if (indexing_stack[j++] < indexing_stack[i])
				rank++;
		}
		stacks->a.addr[i] = rank;
	}
	stacks->a.size = stacks->tmp.size;
	free(indexing_stack);
}
