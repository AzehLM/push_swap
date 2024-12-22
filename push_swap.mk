# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    push_swap.mk                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 17:53:12 by gueberso          #+#    #+#              #
#    Updated: 2024/12/22 14:06:47 by gueberso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

override SRCSDIR	:= srcs/
override SRCS		= $(addprefix $(SRCSDIR), $(SRC))
override SRCSBONUS	= $(addprefix $(SRCSDIR), $(SRCBONUS))


override PARSEDIR	:= parsing/
override INITDIR	:= init/
override OPDIR		:= operations/
override SORTDIR	:= sort/
override CHECKERDIR	:= checker/

SRC	+= $(addprefix $(PARSEDIR), $(addsuffix .c, $(PARSESRC)))

override PARSESRC	:= \
	check_arg \
	indexing \
	parse_params \
	parse_string \
	parse_utils \

SRC += $(addprefix $(INITDIR), $(addsuffix .c, $(INITSRC)))

override INITSRC	:= \
	chunks \
	stacks \
	tab_operations \

SRC += $(addprefix $(OPDIR), $(addsuffix .c, $(OPSRC)))

override OPSRC		:= \
	pushs \
	rev_rotate \
	rotate \
	swaps \

SRC += $(addprefix $(SORTDIR), $(addsuffix .c, $(SORTSRC)))

override SORTSRC	:= \
	basic_sort_a \
	push_swap \
	sort \

SRCBONUS += $(addprefix $(CHECKERDIR), $(addsuffix .c, $(CHECKERSRC)))

override CHECKERSRC	:= \
	checker \
