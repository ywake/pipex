NAME	:= pipex
CC		:= gcc
INCLUDE	:= -I./includes -I./Libft
CFLAGS	:= -g -Wall -Werror -Wextra $(INCLUDE)
LIBS	:= -L./Libft -lft
VPATH	:= srcs

LIBFT	:= ./Libft/libft.a
OBJDIR	:= ./objs/
SRCS	:= main.c error.c utils.c exec.c
OBJS	:= $(SRCS:%.c=$(OBJDIR)%.o)
B_SRCS	:= main_bonus.c error.c utils.c exec.c
B_OBJS	:= $(B_SRCS:%.c=$(OBJDIR)%.o)
B_FLG	:= .bonus_flg
DSTRCTR	:= ./tests/destructor.c

.PHONY: all clean fclean re bonus norm leak Darwin_leak Linux_leak leak_bonus Darwin_leak_bonus Linux_leak_bonus tests

all: $(NAME)

$(OBJDIR)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): ./Libft/*.c
	$(MAKE) bonus -C ./Libft

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

bonus: $(B_FLG)

$(B_FLG): $(LIBFT) $(B_OBJS)
	$(CC) $(CFLAGS) $(B_OBJS) -o $(NAME) $(LIBS)

clean:
	$(MAKE) clean -C ./Libft
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	$(MAKE) fclean -C ./Libft
	rm -f $(NAME) tester leaksout
	rm -rf tester.dSYM/
	rm -rf $(NAME).dSYM/

re: fclean all

norm:
	@printf "\e[31m"; norminette | grep -v -e ": OK!" \
    && exit 1 \
	|| printf "\e[32m%s\n\e[m" "Norm OK!"; printf "\e[m"

tester: $(LIBFT) ./tests/tester/*.c
	$(CC) $(CFLAGS) ./tests/tester/*.c -o tester $(LIBS)

$(DSTRCTR):
	curl https://gist.githubusercontent.com/ywake/793a72da8cdae02f093c02fc4d5dc874/raw/destructor.c > $(DSTRCTR)

Darwin_leak: $(LIBFT) $(OBJS) $(DSTRCTR)
	$(CC) $(CFLAGS) $(OBJS) $(DSTRCTR) -o $(NAME) $(LIBS)

Linux_leak: $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -fsanitize=leak $(OBJS) -o $(NAME) $(LIBS)

leak: $(shell uname)_leak

Darwin_leak_bonus: $(LIBFT) $(B_OBJS) $(DSTRCTR)
	$(CC) $(CFLAGS) $(B_OBJS) $(DSTRCTR) -o $(NAME) $(LIBS)

Linux_leak_bonus: $(LIBFT) $(B_OBJS)
	$(CC) $(CFLAGS) -fsanitize=address $(B_OBJS) -o $(NAME) $(LIBS)

leak_bonus: $(shell uname)_leak_bonus

tests: leak tester
	chmod -r ./tests/infile/no_perm
	bash auto_test.sh $(TEST)
