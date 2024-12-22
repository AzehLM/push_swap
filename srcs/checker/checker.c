/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:17:07 by gueberso          #+#    #+#             */
/*   Updated: 2024/12/22 17:48:10 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"


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
			exec_operation(i, stacks);
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_stacks	stacks;
	char		*line;
	int			size;
	int			valid_op;

	if (ac < 2)
		exit_with_error(ERR_NO_PARAMETERS);
	if (ac == 2)
		size = count_numbers(av[1]);
	else
		size = ac - 1;
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
	if (is_sorted(&stacks) && stacks.b.size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stacks(&stacks);
	return (SUCCESS);
}
