/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:29:29 by gueberso          #+#    #+#             */
/*   Updated: 2024/12/21 18:57:08 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_b(t_stacks *stacks)
{
	if (stacks->b.addr[0] > stacks->b.addr[1])
		exec_operation(SB, stacks);
}

void	sort_three_b(t_stacks *stacks)
{
	int	a;
	int	b;
	int	c;

	a = stacks->b.addr[0];
	b = stacks->b.addr[1];
	c = stacks->b.addr[2];
	if (a > b && b < c && a < c)
		exec_operation(SB, stacks);
	else if (a > b && b > c)
	{
		exec_operation(SB, stacks);
		exec_operation(RRB, stacks);
	}
	else if (a > b && b < c && a > c)
		exec_operation(RB, stacks);
	else if (a < b && b > c && a < c)
	{
		exec_operation(SB, stacks);
		exec_operation(RB, stacks);
	}
	else if (a < b && b > c && a > c)
		exec_operation(RRB, stacks);
}

static int	find_min_pos(t_stacks *stacks)
{
	int	i;
	int	min;
	int	min_pos;

	i = 0;
	min = stacks->b.addr[0];
	min_pos = 0;
	while (i < stacks->b.size)
	{
		if (stacks->b.addr[i] < min)
		{
			min = stacks->b.addr[i];
			min_pos = i;
		}
		i++;
	}
	return (min_pos);
}

void	sort_five_b(t_stacks *stacks)
{
	int	min_pos;

	while (stacks->b.size > 3)
	{
		min_pos = find_min_pos(stacks);
		while (min_pos > 0)
		{
			if (min_pos <= stacks->b.size / 2)
			{
				exec_operation(RB, stacks);
				min_pos--;
			}
			else
			{
				exec_operation(RRB, stacks);
				min_pos = (min_pos + 1) % stacks->b.size;
			}
		}
		exec_operation(PA, stacks);
	}
	sort_three_a(stacks);
	while (stacks->a.size > 0)
		exec_operation(PB, stacks);
}
