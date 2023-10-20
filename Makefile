# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acuva-nu <acuva-nu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 12:35:24 by acuva-nu          #+#    #+#              #
#    Updated: 2023/02/25 16:34:52 by acuva-nu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS       = src/utils.c src/stack.c src/argparser.c          \
						 src/cost.c  src/moves.c src/p.c  src/position.c  \
						 src/push_swap.c src/r.c  src/rr.c  src/s.c       \
						 src/sort_big.c  src/sort_small.c
B_SRC      = 	src/stack.c src/argparser.c \
							src/p.c src/r.c  src/rr.c  \
							src/s.c src/utils.c src/checker.c
OBJS       = ${SRCS:src/%.c=$(OBJ_DIR)/%.o}
B_OBJS     = ${B_SRC:src/%.c=$(B_OBJ_DIR)/%.o}
BUILD_DIR  = build
OBJ_DIR    = ${BUILD_DIR}/obj
B_OBJ_DIR  = ${BUILD_DIR}/b_obj
INCS 			 = inc/
NAME       = ${BUILD_DIR}/push_swap
B_NAME     = ${BUILD_DIR}/checker
CC         = cc
CFLAGS     = -g -Wall -Wextra -Werror
LDFLAGS 	 = -Llibft -lft
RM         = rm -rf

all: ${NAME}

$(OBJ_DIR)/%.o: src/%.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS)

${NAME}: ${OBJS} | $(BUILD_DIR)
	@echo "Compiling push_swap"
	@make -s -C libft
	@${CC} ${CFLAGS}  $^ -o $@  -I ${INCS} ${LDFLAGS}
	@echo "Push_swap created"

$(B_OBJ_DIR)/%.o: src/%.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) -I $(INCS) -c $< -o $@

bonus: ${B_NAME}

${B_NAME}: ${B_OBJS} | $(BUILD_DIR)
	@echo "Compiling checker"
	@make -s -C libft
	@${CC} ${CFLAGS}  $^ -o $@ -I ${INCS} ${LDFLAGS}
	@echo "Checker created"

$(BUILD_DIR):
	@mkdir -p ${BUILD_DIR}
	@mkdir -p ${OBJ_DIR} ${B_OBJ_DIR}

clean:
	@${RM} ${OBJS} ${B_OBJS}
	@make clean -s -C libft

fclean: clean
	@${RM} ${NAME} ${B_NAME}
	@${RM} ${BUILD_DIR}
	@make fclean -s -C libft
	@echo "Push_swap deleted"

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader ${SRCS}
	norminette -R CheckDefine ${INCS}

.PHONY: all re clean fclean bonus
