/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:01:13 by gueberso          #+#    #+#             */
/*   Updated: 2024/12/19 12:42:14 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

typedef enum e_exit
{
	SUCCESS,
	ERR_NO_PARAMETERS,
	ERR_NO_NUMERIC,
	ERR_OUT_OF_RANGE,
	ERR_DUPLICATE,
	ERR_MALLOC,
	ERR_EMPTY_STRING,
	ERR_UNKNOWN
}	t_exit_code;

typedef struct s_array
{
	int	size;
	int	*addr;
}	t_array;

typedef struct s_stacks
{
	t_array	a;
	t_array	b;
	t_array	tmp;
}	t_stacks;

typedef enum e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}	t_op;

/*	----------- parsing ----------------------------------------------------- */

int		check_arg(int ac, char **av, t_stacks *stacks);
int		check_duplicates(int *stack, int size);
int		check_out_of_range(const char *str);
int		count_numbers(const char *str);
int		get_stack_len(int *stack_tmp);
int		is_strdigit(const char *str);
int		parse_params(int ac, char **av, int **stack_tmp);
int		parse_string(const char *str, t_stacks *stacks);

void	exit_with_error(t_exit_code error_code);
void	free_av1(char **split, int *stack, size_t size);
void	free_stacks(t_stacks *stacks);
void	indexing(t_stacks *stacks, int rank);
void	init_stacks(t_stacks *stacks, int size);
void	sort_tmp(t_stacks *stacks);

#endif
