/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:53:40 by gueberso          #+#    #+#             */
/*   Updated: 2024/12/07 17:20:12 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg(int ac, char **av)
{
	if (ac == true)
		return ;
}

void	exit_with_error(t_error error)
{
	static const char	*error_messages[] = {
		"Error: No parameter detected.",
		"Error: Non-numeric parameter detected.",
		"Error: Number out of bounds (must fit in INT_MIN/INT_MAX).",
		"Error: Duplicate values detected.",
	};

	if (error >= ERR_NO_PARAMETERS && error <= ERR_DUPLICATE)
		fprintf(stderr, "%s\n", error_messages[error - 1]);
	else
		fprintf(stderr, "Error: Unknown error occurred.\n");
	exit(error);
}
