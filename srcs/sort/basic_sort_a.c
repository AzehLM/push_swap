/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:17:52 by gueberso          #+#    #+#             */
/*   Updated: 2024/12/20 18:39:03 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_a(t_stacks *stacks)
{
	if (stacks->a.addr[0] > stacks->a.addr[1])
		exec_operation(SA, stacks);
}

void	sort_three_a(t_stacks *stacks)
{
	int	a;
	int	b;
	int	c;

	a = stacks->a.addr[0];
	b = stacks->a.addr[1];
	c = stacks->a.addr[2];
	if (a > b && b < c && a < c)
		exec_operation(SA, stacks);
	else if (a > b && b > c)
	{
		exec_operation(SA, stacks);
		exec_operation(RRA, stacks);
	}
	else if (a > b && b < c && a > c)
		exec_operation(RA, stacks);
	else if (a < b && b > c && a < c)
	{
		exec_operation(SA, stacks);
		exec_operation(RA, stacks);
	}
	else if (a < b && b > c && a > c)
		exec_operation(RRA, stacks);
}

static int	find_min_pos(t_stacks *stacks)
{
	int	i;
	int	min;
	int	min_pos;

	i = 0;
	min = stacks->a.addr[0];
	min_pos = 0;
	while (i < stacks->a.size)
	{
		if (stacks->a.addr[i] < min)
		{
			min = stacks->a.addr[i];
			min_pos = i;
		}
		i++;
	}
	return (min_pos);
}

void	sort_five_a(t_stacks *stacks)
{
	int	min_pos;

	while (stacks->a.size > 3)
	{
		min_pos = find_min_pos(stacks);
		while (min_pos > 0)
		{
			if (min_pos <= stacks->a.size / 2)
			{
				exec_operation(RA, stacks);
				min_pos--;
			}
			else
			{
				exec_operation(RRA, stacks);
				min_pos = (min_pos + 1) % stacks->a.size;
			}
		}
		exec_operation(PB, stacks);
	}
	sort_three_a(stacks);
	while (stacks->b.size > 0)
		exec_operation(PA, stacks);
}
