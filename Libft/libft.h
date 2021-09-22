/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:16:53 by ywake             #+#    #+#             */
/*   Updated: 2021/07/18 11:52:35 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

t_list	*ft_lstnew(void *content);
/*
** ft_lstadd_front: O(1)
*/
void	ft_lstadd_front(t_list **lst, t_list *new);
/*
** ft_lstsize: O(n)
*/
int		ft_lstsize(t_list *lst);
/*
** ft_lstlast: O(n)
*/
t_list	*ft_lstlast(t_list *lst);
/*
** ft_lstadd_back: O(n)
*/
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*
** @param index: 0-based index.
*/
t_list	*ft_lst_at(t_list *lst, size_t index);
/*
** ft_lst_reverse: O(n)
*/
void	ft_lst_reverse(t_list **lst);
/*
** ft_lst_sort: O(n*log(n))
*/
void	ft_lst_sort(t_list **lst, int (*cmp)());
t_list	*ft_lstndup(t_list *list, size_t n);
size_t	ft_lstget_index(t_list *head, t_list *target);
void	ft_lstdrop(t_list **list, t_list *drop, void (*del)(void *));

int		ft_strchr_i(const char *s, int c);
void	free_set(void **dst, void *src);
int		ft_strmap_bool(char const *s, int (*f)(int));
size_t	ft_strcount(char **s);
char	*ft_strndup(const char *s1, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
char	*set_rtn(char **dest, char *source);
int		set_rtn_int(int *dest, int source);
long	set_rtn_long(long *dest, long source);
size_t	ft_min(size_t a, size_t b);
size_t	ft_max(size_t a, size_t b);
int		contain(char **array, char *str);

#endif
