# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    push_swap.mk                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 17:53:12 by gueberso          #+#    #+#              #
#    Updated: 2024/12/20 18:29:47 by gueberso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

override SRCSDIR	:= srcs/
override SRCS		= $(addprefix $(SRCSDIR), $(SRC))

override PARSEDIR	:= parsing/
override INITDIR	:= init/
override OPDIR		:= operations/
override SORTDIR	:= sort/
override MISCDIR	:= misc/

SRC	+= $(addprefix $(PARSEDIR), $(addsuffix .c, $(PARSESRC)))

override PARSESRC	:= \
	check_arg \
	indexing \
	parse_params \
	parse_string \
	parse_utils \

SRC += $(addprefix $(INITDIR), $(addsuffix .c, $(INITSRC)))

override INITSRC	:= \
	init_stacks \
	init_tab_operations \

SRC += $(addprefix $(OPDIR), $(addsuffix .c, $(OPSRC)))

override OPSRC		:= \
	pushs \
	rev_rotate \
	rotate \
	swaps \

SRC += $(addprefix $(SORTDIR), $(addsuffix .c, $(SORTSRC)))

override SORTSRC	:= \
	basic_sort_a \
	basic_sort_b \
	check_sorted \

SRC += $(addprefix $(MISCDIR), $(addsuffix .c, $(MISCSRC)))

override MISCSRC	:= \
	main \

