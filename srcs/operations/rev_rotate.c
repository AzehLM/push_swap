/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:00:54 by gueberso          #+#    #+#             */
/*   Updated: 2024/12/19 19:07:11 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a(t_stacks *stacks)
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
	ft_printf("rra\n");
}

void	rev_rotate_b(t_stacks *stacks)
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
	ft_printf("rrb\n");
}

void	rev_rotate_both(t_stacks *stacks)
{
	if (stacks->a.size < 2 || stacks->b.size < 2)
		return ;
	rev_rotate_a(stacks);
	rev_rotate_b(stacks);
	ft_printf("rrr\n");
}
