/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:02:43 by gueberso          #+#    #+#             */
/*   Updated: 2024/12/19 21:39:01 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_operation(t_op op, t_stacks *stacks)
{
	static const t_operation	operations[] = {\
		[SA] = &swap_a, \
		[SB] = &swap_b, \
		[SS] = &swap_both, \
		[PA] = &push_a, \
		[PB] = &push_b, \
		[RA] = &rotate_a, \
		[RB] = &rotate_b, \
		[RR] = &rotate_both, \
		[RRA] = &rev_rotate_a, \
		[RRB] = &rev_rotate_b, \
		[RRR] = &rev_rotate_both
	};

	if (op >= SA && op <= RRR)
		operations[op](stacks);
}
