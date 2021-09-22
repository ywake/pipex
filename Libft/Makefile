# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/22 15:19:36 by ywake             #+#    #+#              #
#    Updated: 2021/07/19 16:49:52 by ywake            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libft.a
CC		:= gcc
INCLUDE	:= -I./
CFLAGS	:= -g -Wall -Werror -Wextra $(INCLUDE)
SRC		:= ft_strlen.c ft_strlcpy.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_memset.c ft_memcpy.c ft_memchr.c ft_memccpy.c ft_bzero.c ft_memcmp.c ft_memmove.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
BONUS	:= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_strmap_bool_bonus.c ft_strcount_bonus.c ft_strndup_bonus.c free_set_bonus.c ft_strchr_i_bonus.c ft_lst_at_bonus.c ft_lst_reverse_bonus.c ft_lst_sort_bonus.c ft_strcmp_bonus.c set_rtn_bonus.c ft_lstndup_bonus.c ft_min_max_bonus.c ft_lstget_index_bonus.c ft_lstdrop_bonus.c contain_bonus.c
OBJ		:= $(SRC:%.c=%.o)
OBJBONUS:= $(BONUS:%.c=%.o)
BONUSFLG:= .bonus_flg

.PHONY: all clean fclean re bonus

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(BONUSFLG)

$(BONUSFLG): $(OBJ) $(OBJBONUS)
	@touch $(BONUSFLG)
	ar rcs $(NAME) $(OBJ) $(OBJBONUS)

clean:
	rm -f $(OBJ) $(OBJBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all
