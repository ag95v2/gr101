/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:42:53 by bgian             #+#    #+#             */
/*   Updated: 2020/01/24 17:18:21 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# include "bbtree_utils.h"
# include "ft_ptree.h"

int					ft_strcmp(const char *s1, const char *s2);
size_t				ft_strlen(const char *s);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *haystack, \
		const char *needle, size_t len);
char				*ft_strncpy(char *dest, const char *src, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strcat(char *dest, const char *src);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memccpy(void *dest, const void *src, \
		int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isprint(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
int					ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_strrev(char *s);
char				*ft_itoa_base(long long value, char *base, int sgn);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void				*ft_memdup(void *c, size_t n);
t_list				*ft_lstappend(t_list *lst, void const *content,\
		size_t content_size);
void				del_simple(void *content, size_t content_size);

int					get_next_line(const int fd, char **line);

void				ft_swap(void *a, void *b, size_t len);
void				ft_swapint(int *a, int *b);
int					ft_minval_int(int *a, unsigned int len);
int					ft_maxval_int(int *a, unsigned int len);
int					*ft_min_int(int *arr, int len);
int					*ft_max_int(int *arr, int len);
void				ft_bsort_int(int *a, unsigned int len, int ascending);
void				ft_print_array(int *a, int len);
int					*ft_array_subtract(int *arr, unsigned int len, int number,\
		int in_place);
char				*ftoa(long double x, int precision);

int					ft_printf(const char *format, ...);
int					ft_fprintf(int fd, const char *format, ...);

char				*ft_straddchar(char *s, char c);

/*
** Add data point to start of the linked list
** return 0 in case of errors
*/

int					ft_lstadd_data(t_list **lst, void *content,\
		size_t content_size);

int					ft_lstlen(t_list *l);
char				*ft_path_append(char *path, char *name);
int					ft_is_escaped(const char *start, const char *symbol,\
		char escape_char);

int					ft_is_part_of_word(const char *start,\
		const char *position,\
		char sep,\
		char escape);
char				**ft_strsplit_unescaped(char const *s, char c,\
		char escape);

# define N_CHILDREN 256

/*
** Prefix tree data structure
** key - value pairs, keys are strings, values - *void
** value must be freeable (TODO: arbitrary)
**
** NULL value means lack of value
** If no children and no value, we can delete a node and check parent
** (not really needed)
*/

typedef struct		s_ptree
{
	struct s_ptree	*child[N_CHILDREN];
	void			*value;
}					t_ptree;

t_ptree				*new_tree(void);

/*
** Return value of key if it exists
*/

void				*search_key(t_ptree *tree, char *key);

/*
** Return nonzero on success
** Remove old entry properly if needed
** If NULL is provided instead of tree, create a new tree
*/

int					insert_value(t_ptree *tree, char *key, void *value);
void				del_key(t_ptree *tree, char *key);
void				del_tree(t_ptree *tree);

/*
** Copy tree with all contents.
** Modification of copy never affects original tree
*/

t_ptree				*copy_ptree(t_ptree *tree);

typedef	struct		s_key_value
{
	char			*key;
	void			*value;
}					t_key_value;

/*
** Convert ptree to list of  key-value pairs
**
** If no values are present on the tree and some keys (yes, this is possible),
** return single node of list with empty content.
**
** Return 0 in case of malloc errors.
*/

t_list				*ptree_to_kvpairs(t_ptree *tree);

#endif
