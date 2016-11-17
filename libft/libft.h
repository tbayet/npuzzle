/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:20:24 by tbayet            #+#    #+#             */
/*   Updated: 2016/06/27 10:46:17 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

typedef struct			s_list
{
	char				*content;
	size_t				content_size;
	int					fd;
	int					eof;
	struct s_list		*next;
}						t_list;

typedef struct s_list	t_save;

void					ft_deltab(char **tab);
char					**ft_tabdup(char **tab);
int						ft_tablen(char **tab);
char					**ft_revtab(char **tab);
char					**ft_sorttab(char **tab);
char					**ft_delstrtab(char **tab, int i);
int						ft_charstr(char *str, char c);
size_t					ft_strlen(const char *s);
int						ft_toupper(int c);
int						ft_tolower(int c);
void					*ft_memalloc(size_t size);
int						ft_memdel(void **ap);
char					*ft_strnew(size_t size);
int						ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s, char (*f)
						(unsigned int, char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s, unsigned int start,
						size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char const *s, char c);
char					**ft_strsplitone(char const *s, char c);
char					*ft_itoa(int n);
void					ft_putchar(char c);
void					ft_putstr(char const *s);
void					ft_putendl(char const *s);
void					ft_putnbr(int n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memccpy(void *dst, const void *src, int c, size_t
						n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
char					*ft_strdup(const char *s1);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strncpy(char *dst, const char *src, size_t n);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strncat(char *s1, const char *s2, size_t n);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(const char *s1, const char *s2);
char					*ft_strnstr(const char *s1, const char *s2, size_t n);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_atoi(const char *str);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdelone(t_list **alst, void (*del)(void *,
						size_t));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int						ft_lstlen(t_list **lst);
void					ft_lstdelthis(t_list **lst, t_list *this);
char					*ft_strrealloc(char *str, int len);
char					*ft_strsort(char *str);
char					*ft_strreplace(char *str, char c1, char c2);
char					*ft_strreverse(char *str);
char					*ft_strshift(char *str, int nb);
void					ft_puttab(char **tab);
size_t					ft_sqrn(size_t nb);
char					*ft_itoabasep(int nb, unsigned int base, int precision);
int						*ft_intnew(int len);
void					ft_putstrn(char *str, int n);
void					ft_putstrcat(char *str, int start, int len);
char					*ft_strcut(char *str, int start);
int						get_next_line(int const fd, char **line);
int						ft_voidstr(char *str);
void					ft_putcolor_fd(char *str, char *color, int fd);
char					*ft_strndup(const char *s1, size_t n);
int					ft_nbwords(char *str);

#endif
