/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:31:51 by gueberso          #+#    #+#             */
/*   Updated: 2024/12/21 13:37:22 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stacks *stacks)
{
	int	i;

	if (stacks->a.size <= 1)
		return (1);
	i = 0;
	while (i < stacks->a.size - 1)
	{
		if (stacks->a.addr[i] > stacks->a.addr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
