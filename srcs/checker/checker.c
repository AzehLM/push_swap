/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:17:07 by gueberso          #+#    #+#             */
/*   Updated: 2025/09/25 22:08:37 by gueberso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

static void	exec_operation_checker(t_op op, t_stacks *stacks)
{
	const t_operation	operations[] = {\
		[SA] = &swap_a_checker, \
		[SB] = &swap_b_checker, \
		[SS] = &swap_both_checker, \
		[PA] = &push_a_checker, \
		[PB] = &push_b_checker, \
		[RA] = &rotate_a_checker, \
		[RB] = &rotate_b_checker, \
		[RR] = &rotate_both_checker, \
		[RRA] = &rev_rotate_a_checker, \
		[RRB] = &rev_rotate_b_checker, \
		[RRR] = &rev_rotate_both_checker
	};

	if (op >= SA && op <= RRR)
		operations[op](stacks);
}

static int	read_and_execute_op(t_stacks *stacks, char *line)
{
	const char	*op_names[] = {
		"sa\n", "sb\n", "ss\n", "pa\n", "pb\n",
		"ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"
	};
	int			i;

	i = 0;
	while (i <= RRR)
	{
		if (!ft_strncmp(line, op_names[i], ft_strlen(op_names[i])))
		{
			exec_operation_checker(i, stacks);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	pre_check_arg(int ac, char **av, int size)
{
	if (ac < 2)
		exit_with_error(ERR_NO_PARAMETERS);
	if (ac == 2)
	{
		size = count_numbers(av[1]);
	}
	else
		size = ac - 1;
	return (size);
}

static void	check_is_sorted(t_stacks *stacks)
{
	if (is_sorted(stacks) && stacks->b.size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int ac, char **av)
{
	t_stacks	stacks;
	char		*line;
	int			size;
	int			valid_op;

	size = pre_check_arg(ac, av, 0);
	init_stacks(&stacks, size);
	check_arg(ac, av, &stacks);
	ft_memcpy(stacks.a.addr, stacks.tmp.addr, size * sizeof(int));
	stacks.a.size = stacks.tmp.size;
	line = get_next_line(0);
	while (line)
	{
		valid_op = read_and_execute_op(&stacks, line);
		free(line);
		if (!valid_op)
		{
			free_stacks(&stacks);
			exit_with_error(ERR_UNKNOWN);
		}
		line = get_next_line(0);
	}
	check_is_sorted(&stacks);
	free_stacks(&stacks);
	return (SUCCESS);
}
