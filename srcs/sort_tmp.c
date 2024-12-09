/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:45:44 by gueberso          #+#    #+#             */
/*   Updated: 2024/12/09 12:24:18 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_tmp(int *stack_tmp, int size)
{
	int tmp = 0;
	int i = 0;
	int min;
	int j;

	while (i < size - 1)
	{
		min = i;
		j = i + 1;
		while (j < size)
		{
			if (stack_tmp[j] < stack_tmp[min])
				min = j;
			j++;
		}
		if (min != i)
		{
			tmp = stack_tmp[i];
			stack_tmp[i] = stack_tmp[min];
			stack_tmp[min] = tmp;
		}
		i++;
	}
}
