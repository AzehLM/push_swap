/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:37:20 by gueberso          #+#    #+#             */
/*   Updated: 2024/12/21 17:14:20 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	update_chunk(t_stacks *stacks, t_chunk *chunk)
{
	int	i;
	int	found;

	chunk->min = INT_MAX;
	chunk->max = INT_MIN;
	found = 0;
	i = 0;
	while (i < stacks->a.size)
	{
		if (stacks->a.addr[i] >= chunk->start \
			&& stacks->a.addr[i] <= chunk->end)
		{
			if (!found || stacks->a.addr[i] < chunk->min)
				chunk->min = stacks->a.addr[i];
			if (!found || stacks->a.addr[i] > chunk->max)
				chunk->max = stacks->a.addr[i];
			found = 1;
		}
		i++;
	}
	if (!found)
	{
		chunk->min = -1;
		chunk->max = -1;
	}
}

int	is_chunk_empty(t_stacks *stacks, t_chunk *chunk)
{
	int	i;

	i = 0;
	while (i < stacks->a.size)
	{
		if (stacks->a.addr[i] >= chunk->start \
			&& stacks->a.addr[i] <= chunk->end)
			return (1);
		i++;
	}
	return (0);
}

void	next_chunk(t_chunk *chunk)
{
	chunk->start = chunk->end + 1;
	chunk->end = chunk->start + chunk->size - 1;
}

void	init_chunk(t_stacks *stacks, t_chunk *chunk)
{
	if (stacks->tmp.size <= 100)
		chunk->size = 15;
	else if (stacks->tmp.size <= 500)
		chunk->size = 30;
	else
		chunk->size = stacks->tmp.size / 15;
	chunk->start = 1;
	chunk->end = chunk->size;
	chunk->total_chuncks = (stacks->tmp.size + chunk->size - 1) / chunk->size;
	update_chunk(stacks, chunk);
}
