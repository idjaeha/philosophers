NAME=philo
CFLAGS=-Wall -Wextra -Werror
SRCS_NAME=	main.c\
			ft_atoi.c\
			ft_print.c\
			init.c\
			philo_error.c
INCFALGS=-I./includes
SRCS_DIR= ./srcs
SRCS=$(addprefix $(SRCS_DIR)/, $(SRCS_NAME))
OBJS_NAME= $(SRCS_NAME:.c=.o)
OBJS_DIR= ./objs
OBJS= $(addprefix $(OBJS_DIR)/, $(OBJS_NAME))
INCS_NAME=	philosophers.h\
			philo_define.h\
			philo_types.h
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