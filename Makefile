# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akashets <akashets@42wolfsburg.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 12:15:56 by akashets          #+#    #+#              #
#    Updated: 2023/02/12 14:49:40 by akashets         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	op_push.c op_swap.c op_rotate.c op_rev_rotate.c \
		utils_a_err.c create_stack.c parsing_input_check_utils.c\
		parsing_input_check.c parsing.c push_swap.c push_swap_utils.c push_swap_small.c \
		calc_cost_utils.c calc_cost.c

SRC_MAIN = 	main.c

SRCS_BONUS = 	checker.c

NAME = push_swap
BONUS = checker

LIBFT = includes/libft/

OBJS_DIR = objs/
OBJS_BONUS_DIR = objs_bonus/
SRCS_DIR = src/push_swap/
SRCS_BONUS_DIR = src/checker/

OBJS = $(SRCS:.c=.o)
OBJ_MAIN = $(SRC_MAIN:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))
OBJECT_MAIN_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJ_MAIN))
OBJECTS_BONUS_PREFIXED = $(addprefix $(OBJS_BONUS_DIR), $(OBJS_BONUS))
SOURCES_PREFIXED = $(addprefix $(SRCS_DIR), $(SRCS))
SOURCE_MAIN_PREFIXED = $(addprefix $(SRCS_DIR), $(SRC_MAIN))
SOURCES_BONUS_PREFIXED = $(addprefix $(SRCS_BONUS_DIR), $(SRCS_BONUS))

CC = gcc

CC_FLAGS = -Wall -Wextra -Werror

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c includes/push_swap.h
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	@gcc $(CC_FLAGS) -c $< -o $@

$(OBJS_BONUS_DIR)%.o : $(SRCS_BONUS_DIR)%.c includes/push_swap.h
	@mkdir -p $(OBJS_BONUS_DIR)
	@echo "Compiling: $<"
	@gcc $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED) $(OBJECT_MAIN_PREFIXED)
	@make -C $(LIBFT)
	@gcc -o $(NAME) $(OBJECTS_PREFIXED) $(OBJECT_MAIN_PREFIXED) includes/libft/libft.a

$(BONUS): $(OBJECTS_BONUS_PREFIXED) $(OBJECTS_PREFIXED)
	@make -C $(LIBFT)
	@gcc -o $(BONUS) $(OBJECTS_BONUS_PREFIXED) $(OBJECTS_PREFIXED) includes/libft/libft.a

bonus: $(BONUS)

all: $(NAME) $(BONUS)

clean:
	@rm -rf $(OBJS_DIR)
	@rm -rf $(OBJS_BONUS_DIR)
	@make fclean -C $(LIBFT)


fclean: clean
	@rm -f $(NAME)
	@rm -f $(BONUS)

re: fclean all
