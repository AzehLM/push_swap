/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:01:13 by gueberso          #+#    #+#             */
/*   Updated: 2024/12/09 16:49:30 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include <limits.h>

// # define SA "SA"
// # define SA "SA"
// # define SA "SA"
// # define SA "SA"
// # define SA "SA"
// # define SA "SA"
// # define SA "SA"
// # define SA "SA"

typedef enum e_error
{
	SUCCESS,
	ERR_NO_PARAMETERS,
	ERR_NO_NUMERIC,
	ERR_OUT_OF_RANGE,
	ERR_DUPLICATE,
	ERR_MALLOC,
	ERR_UNKNOWN
}	t_error;

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

int		check_arg(int ac, char **av, int **stack_tmp);
int		check_duplicates(int *stack_tmp, int size);
int		parse_string(const char *str, int **stack_tmp);
void	exit_with_error(t_error error);
void	sort_tmp(int *stack_tmp, int size);

/*	----------- parse_utils ----------------------------------------------- */

int		check_out_of_range(const char *str);
int		is_strdigit(const char *str);



int		parse_params(int ac, char **av, int **stack_tmp);

#endif
