/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:45:44 by gueberso          #+#    #+#             */
/*   Updated: 2024/12/19 12:33:04 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_tmp(t_stacks *stacks)
{
	static int	tmp = 0;
	static int	i = 0;
	static int	min;
	static int	j;

	while (i < stacks->tmp.size - 1)
	{
		min = i;
		j = i + 1;
		while (j < stacks->tmp.size)
		{
			if (stacks->tmp.addr[j] < stacks->tmp.addr[min])
				min = j;
			j++;
		}
		if (min != i)
		{
			tmp = stacks->tmp.addr[i];
			stacks->tmp.addr[i] = stacks->tmp.addr[min];
			stacks->tmp.addr[min] = tmp;
		}
		i++;
	}
}
