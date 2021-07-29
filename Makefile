NAME	:= pipex
CC		:= gcc
INCLUDE	:= -I./includes -I./Libft
CFLAGS	:= -g -Wall -Werror -Wextra $(INCLUDE)
LIBFT	:= ./libft.a
LIBS	:= -L. -lft
SRCDIR	:= ./srcs/
SRCS	:= main.c readfile.c error.c
OBJS	:= $(SRCS:%.c=$(SRCDIR)%.o)
B_SRCS	:= main_bonus.c
B_OBJS	:= $(B_SRCS:%.c=$(SRCDIR)%.o)
B_FLG	:= .bonus_flg

.PHONY: all clean fclean re bonus norm leak leak_bonus tests

all: $(NAME)

%.o: $(SRCDIR)%.c *.h
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): ./Libft/*.c
	$(MAKE) bonus -C ./Libft
	cp ./Libft/libft.a ./libft.a

$(NAME):  $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

bonus: $(B_FLG)

$(B_FLG): $(LIBFT) $(B_OBJS)
	$(CC) $(CFLAGS) $(B_OBJS) -o $(NAME) $(LIBS)

clean:
	$(MAKE) clean -C ./Libft
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f libft.a
	rm -f $(NAME)

re: fclean all

norm:
	@printf "\e[31m"; norminette srcs includes Libft tests/**/test.c | grep -v ": OK!" \
	|| printf "\e[32m%s\n\e[m" "Norm OK!"; printf "\e[m"

# leak: $(LIBFT) $(OBJS)
# 	$(CC) $(CFLAGS) $(OBJS) ./tests/sharedlib.c -o $(NAME) $(LIBS)

# leak_bonus: $(LIBFT) $(B_OBJS)
# 	$(CC) $(CFLAGS) $(B_OBJS) ./tests/sharedlib.c -o $(B_NAME) $(LIBS)

tester: $(LIBFT) ./srcs/tester/*.c
	$(CC) $(CFLAGS) ./srcs/tester/*.c -o tester $(LIBS)

Darwin_leak: $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) ./tests/sharedlib.c -o $(NAME) $(LIBS)

Linux_leak: $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -fsanitize=leak $(B_OBJS) -o $(B_NAME) $(LIBS)

leak: $(shell uname)_leak

debug:
	$(CC) $(CFLAGS) -fsanitize=address $(B_OBJS) -o $(B_NAME) $(LIBS)

tests: leak tester
	bash auto_test.sh $(TEST)\
	&& $(MAKE) norm
