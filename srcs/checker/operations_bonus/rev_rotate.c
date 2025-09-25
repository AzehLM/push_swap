/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 21:53:20 by gueberso          #+#    #+#             */
/*   Updated: 2025/09/25 21:57:41 by gueberso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a_checker(t_stacks *stacks)
{
	int	tmp;
	int	i;

	if (stacks->a.size < 2)
		return ;
	i = stacks->a.size - 1;
	tmp = stacks->a.addr[i];
	while (i > 0)
	{
		stacks->a.addr[i] = stacks->a.addr[i - 1];
		i--;
	}
	stacks->a.addr[0] = tmp;
}

void	rev_rotate_b_checker(t_stacks *stacks)
{
	int	tmp;
	int	i;

	if (stacks->b.size < 2)
		return ;
	i = stacks->b.size - 1;
	tmp = stacks->b.addr[i];
	while (i > 0)
	{
		stacks->b.addr[i] = stacks->b.addr[i - 1];
		i--;
	}
	stacks->b.addr[0] = tmp;
}

void	rev_rotate_both_checker(t_stacks *stacks)
{
	if (stacks->a.size < 2 || stacks->b.size < 2)
		return ;
	rev_rotate_a_checker(stacks);
	rev_rotate_b_checker(stacks);
}
