NAME	:= push_swap

BONUS	:= checker

include push_swap.mk

BUILD_DIR	:= .obj/
OBJS 		:= $(patsubst $(SRCSDIR)%.c,$(BUILD_DIR)%.o,$(SRCS))
OBJSB		:= $(patsubst $(SRCSDIR)%.c,$(BUILD_DIR)%.o,$(SRCSBONUS))
DEPS		:= $(OBJS:.o=.d)
DEPSB		:= $(OBJSB:.o=.d)

# ********** FLAGS AND COMPILATION FLAGS ************************************* #

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g3
CPPFLAGS	:= -MMD -MP -I incs/ -I libft/incs/

RM			:= rm -f
RMDIR		+= -r
MAKEFLAGS	+= --no-print-directory

.DEFAULT_GOAL	:= all

-include $(DEPS)
-include $(DEPSB)

# ********** RULES *********************************************************** #

.PHONY: all
all: $(NAME)

$(NAME): libft/libft.a $(OBJS) 
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(OBJS) -L libft -lft
	@echo "\n$(GREEN_BOLD)✓ $(NAME) is ready$(RESETC)\n"

libft/libft.a: FORCE
	@$(MAKE) -C libft/

$(BUILD_DIR)%.o: $(SRCSDIR)%.c
	@mkdir -p $(dir $@)
	@echo "$(CYAN)[Compiling]$(RESETC) $<"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

.PHONY: bonus
bonus: .bonus

.bonus: libft/libft.a $(OBJSB)	
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $(BONUS) $(OBJSB) -L libft -lft
	@echo "\n$(GREEN_BOLD)✓ $(BONUS) is ready$(RESETC)"
	@touch .bonus

$(BUILD_DIR)checker/%.o: $(SRCSDIR)checker/%.c $(NAME)
	@mkdir -p $(dir $@)
	@echo "$(CYAN)[Compiling]$(RESETC) $<"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	@$(MAKE) clean -C libft/
	@$(RM) $(OBJS) $(DEPS) $(OBJSB) $(DEPSB) .bonus
	@echo "$(RED_BOLD)[Cleaning]$(RESETC)"

.PHONY: fclean
fclean: clean
	@$(MAKE) fclean -C libft/
	$(RM) $(RMDIR) $(NAME) $(BONUS) $(BUILD_DIR)
	@echo "$(RED_BOLD)✓ push_swap is fully cleaned!$(RESETC)"

.PHONY: re
re: fclean all

.PHONY: FORCE
FORCE:

.SILENT: clean fclean

# ********** COLORS AND BACKGROUND COLORS ************************************ #

RESETC				:=	\033[0m

GREEN_BOLD			:= \033[1;32m
RED_BOLD			:= \033[1;31m
CYAN				:= \033[0;36m

