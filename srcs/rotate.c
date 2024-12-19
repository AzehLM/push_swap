/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:56:49 by gueberso          #+#    #+#             */
/*   Updated: 2024/12/19 19:00:19 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stacks *stacks)
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
	ft_printf("ra\n");
}

void	rotate_b(t_stacks *stacks)
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
	ft_printf("rb\n");
}

void	rotate_both(t_stacks *stacks)
{
	if (stacks->a.size < 2 || stacks->b.size < 2)
		return ;
	rotate_a(stacks);
	rotate_b(stacks);
	ft_printf("rr\n");
}
