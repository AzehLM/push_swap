/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 21:53:22 by gueberso          #+#    #+#             */
/*   Updated: 2025/09/25 21:57:00 by gueberso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a_checker(t_stacks *stacks)
{
	int	i;

	if (stacks->b.size == 0)
		return ;
	i = stacks->a.size;
	while (i > 0)
	{
		stacks->a.addr[i] = stacks->a.addr[i - 1];
		i--;
	}
	stacks->a.addr[0] = stacks->b.addr[0];
	i = 0;
	while (i < stacks->b.size - 1)
	{
		stacks->b.addr[i] = stacks->b.addr[i + 1];
		i++;
	}
	stacks->a.size++;
	stacks->b.size--;
}

void	push_b_checker(t_stacks *stacks)
{
	int	i;

	if (stacks->a.size == 0)
		return ;
	i = stacks->b.size;
	while (i > 0)
	{
		stacks->b.addr[i] = stacks->b.addr[i - 1];
		i--;
	}
	stacks->b.addr[0] = stacks->a.addr[0];
	i = 0;
	while (i < stacks->a.size - 1)
	{
		stacks->a.addr[i] = stacks->a.addr[i + 1];
		i++;
	}
	stacks->b.size++;
	stacks->a.size--;
}
