/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:27:20 by gueberso          #+#    #+#             */
/*   Updated: 2024/12/19 19:10:17 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stacks *stacks)
{
	int	tmp;

	if (stacks->a.size < 2)
		return ;
	tmp = stacks->a.addr[0];
	stacks->a.addr[0] = stacks->a.addr[1];
	stacks->a.addr[1] = tmp;
	ft_printf("sa\n");
}

void	swap_b(t_stacks *stacks)
{
	int	tmp;

	if (stacks->b.size < 2)
		return ;
	tmp = stacks->b.addr[0];
	stacks->b.addr[0] = stacks->b.addr[1];
	stacks->b.addr[1] = tmp;
	ft_printf("sb\n");
}

void	swap_both(t_stacks *stacks)
{
	if (stacks->a.size < 2 || stacks->b.size < 2)
		return ;
	swap_a(stacks);
	swap_b(stacks);
	ft_printf("ss\n");
}
