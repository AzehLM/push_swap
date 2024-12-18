/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:59:45 by gueberso          #+#    #+#             */
/*   Updated: 2024/12/18 17:24:48 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_stacks *stacks)
{
	if (stacks->a.addr)
		free(stacks->a.addr);
	stacks->a.addr = NULL;
	if (stacks->b.addr)
		free(stacks->b.addr);
	stacks->b.addr = NULL;
	if (stacks->tmp.addr)
		free(stacks->tmp.addr);
	stacks->tmp.addr = NULL;
}

void	init_stacks(t_stacks *stacks, int size)
{
	stacks->a.size = 0;
	stacks->a.addr = malloc(sizeof(int) * size);
	if ()
}

