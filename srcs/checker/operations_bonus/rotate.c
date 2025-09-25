/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 21:53:18 by gueberso          #+#    #+#             */
/*   Updated: 2025/09/25 21:57:31 by gueberso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_checker(t_stacks *stacks)
{
	int	i;
	int	tmp;

	if (stacks->a.size < 2)
		return ;
	tmp = stacks->a.addr[0];
	i = 0;
	while (i < stacks->a.size -1)
	{
		stacks->a.addr[i] = stacks->a.addr[i + 1];
		i++;
	}
	stacks->a.addr[i] = tmp;
}

void	rotate_b_checker(t_stacks *stacks)
{
	int	i;
	int	tmp;

	if (stacks->b.size < 2)
		return ;
	tmp = stacks->b.addr[0];
	i = 0;
	while (i < stacks->b.size -1)
	{
		stacks->b.addr[i] = stacks->b.addr[i + 1];
		i++;
	}
	stacks->b.addr[i] = tmp;
}

void	rotate_both_checker(t_stacks *stacks)
{
	if (stacks->a.size < 2 || stacks->b.size < 2)
		return ;
	rotate_a_checker(stacks);
	rotate_b_checker(stacks);
}
