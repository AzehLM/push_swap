/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 21:53:13 by gueberso          #+#    #+#             */
/*   Updated: 2025/09/25 21:57:27 by gueberso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a_checker(t_stacks *stacks)
{
	int	tmp;

	if (stacks->a.size < 2)
		return ;
	tmp = stacks->a.addr[0];
	stacks->a.addr[0] = stacks->a.addr[1];
	stacks->a.addr[1] = tmp;
}

void	swap_b_checker(t_stacks *stacks)
{
	int	tmp;

	if (stacks->b.size < 2)
		return ;
	tmp = stacks->b.addr[0];
	stacks->b.addr[0] = stacks->b.addr[1];
	stacks->b.addr[1] = tmp;
}

void	swap_both_checker(t_stacks *stacks)
{
	if (stacks->a.size < 2 || stacks->b.size < 2)
		return ;
	swap_a_checker(stacks);
	swap_b_checker(stacks);
}
