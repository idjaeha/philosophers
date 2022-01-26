NAME=philosophers
CFLAGS=-Wall -Wextra -Werror
SRCS_NAME=	philosophers.c\
			ps_operation_1.c\
			ps_operation_2.c\
			ps_lst.c\
			ps_error.c\
			ft_atoi.c\
			ft_string.c\
			ft_memory.c\
			ft_print.c\
			ft_split.c\
			order_nums.c\
			sort_utility.c\
			ft_sort.c\
			ft_sort_when_less_5.c\
			init_nums.c
INCFALGS=-I./includes
SRCS_DIR= ./srcs
SRCS=$(addprefix $(SRCS_DIR)/, $(SRCS_NAME))
OBJS_NAME= $(SRCS_NAME:.c=.o)
OBJS_DIR= ./objs
OBJS= $(addprefix $(OBJS_DIR)/, $(OBJS_NAME))
INCS_NAME=	philosophers.h\
			ps_define.h\
			ps_types.h
INCS_DIR= ./includes
INCS=$(addprefix $(INCS_DIR)/, $(INCS_NAME))

all: $(NAME)

.PHONY: test
test: re
	@gcc $(OBJS) $(INCFALGS) -o $(NAME)
	@./$(NAME)

.PHONY: gtest
gtest: re
	@gcc $(OBJS) -g3 -fsanitize=address $(INCFALGS) -o $(NAME)
	@./$(NAME)

$(NAME): $(OBJS) $(INCS)
	@gcc $(CFLAGS) $(INCFALGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir $(OBJS_DIR) 2> /dev/null || true
	@gcc $(CFLAGS) $(INCFALGS) -o $@ -c $<

clean:
	@rm -rf ./objs

fclean: clean
	@rm -rf $(NAME)

re : fclean all