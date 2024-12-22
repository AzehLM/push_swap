/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 12:30:20 by gueberso          #+#    #+#             */
/*   Updated: 2024/12/22 12:45:50 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_by_chunk_2nd_part(t_stacks *stacks, t_chunk *chunk)
{
	int	middle;

	if (stacks->a.addr[0] > stacks->tmp.size - 5)
		exec_operation(RA, stacks);
	else
	{
		middle = (chunk->min + chunk->max) / 2;
		exec_operation(PB, stacks);
		chunk->end++;
		if (stacks->b.addr[0] > middle)
			exec_operation(RB, stacks);
		}
}

static void	sort_by_chunk(t_stacks *stacks, t_chunk *chunk)
{
	int		middle;

	middle = 0;
	while (stacks->a.size > 5)
	{
		update_chunk(stacks, chunk);
		if (!is_chunk_empty(stacks, chunk))
		{
			next_chunk(chunk);
			continue ;
		}
		if (stacks->a.addr[0] >= chunk->start \
			&& stacks->a.addr[0] <= chunk->end)
			sort_by_chunk_2nd_part(stacks, chunk);
		else
			exec_operation(RA, stacks);
	}
}

static	void	push_back_2nd_part(t_stacks *stacks, int max_pos)
{
	while (max_pos > 0)
	{
		if (max_pos <= stacks->b.size / 2)
		{
			exec_operation(RB, stacks);
			max_pos--;
		}
		else
		{
			exec_operation(RRB, stacks);
			max_pos = (max_pos + 1) % stacks->b.size;
		}
	}
	exec_operation(PA, stacks);
}

static void	push_back(t_stacks *stacks)
{
	int	max_pos;
	int	pos;
	int	max;

	max_pos = 0;
	pos = 0;
	max = stacks->b.addr[0];
	while (pos < stacks->b.size)
	{
		if (stacks->b.addr[pos] > max)
		{
			max = stacks->b.addr[pos];
			max_pos = pos;
		}
		pos++;
	}
	push_back_2nd_part(stacks, max_pos);
}

void	sort_hmoon(t_stacks *stacks)
{
	t_chunk	chunk;

	init_chunk(stacks, &chunk);
	sort_by_chunk(stacks, &chunk);
	sort_five_a(stacks);
	while (stacks->b.size > 0)
		push_back(stacks);
}
