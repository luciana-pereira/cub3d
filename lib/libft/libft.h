/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 02:53:09 by lucperei          #+#    #+#             */
/*   Updated: 2023/12/09 15:18:26 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define BUFFER_SIZE 42

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}	t_list;

// Vou incluir e atualizar lista de funções conforme for necessitando da utilização para não ficar pesado

// Funções auxiliares da GNL adaptado
// int		find_char_index(const char *str, int target);
// size_t	custom_strlcpy(char *destination, const char *source, size_t size);
// size_t	custom_strlcat(char *destination, const char *source, size_t size);
// char	*custom_substr(const char *str, unsigned int start, size_t length);

// char	*get_next_line(int fd);
// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void*));
// t_list	*ft_lstnew(void *content);
// t_list	*ft_lstlast(t_list *lst);

// int		ft_isalnum(int c);
// int		ft_isalpha(int c);
// int		ft_isascii(int c);
// int		ft_isdigit(int c);
// int		ft_isprint(int c);
// int		ft_isspace(int c);
// int		ft_toupper(int c);
// int		ft_tolower(int c);
// int		ft_atoi(const char *s);
// int		ft_lstsize(t_list *lst);
// int		ft_memcmp(const void *s1, const void *s2, size_t n);
// int		ft_strncmp(const char *s1, const char *s2, size_t n);

size_t	ft_strlen(const char *s);
// size_t	ft_strlcpy(char *dst, const char *src, size_t size);
// size_t	ft_strlcat(char *dst, const char *src, size_t size);

// void	*ft_memcpy(void *dest, const void *src, size_t n);
// void	*ft_memmove(void *dest, const void *src, size_t n);
// void	*ft_memchr(const void *s, int c, size_t n);
// void	*ft_memset(void *s, int c, size_t n);
// void	*ft_calloc(size_t nmemb, size_t size);
// void	ft_bzero(void *s, size_t n);
// void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
// void	ft_putnbr_fd(int n, int fd);
// void	ft_lstdelone(t_list *lst, void (*del)(void*));
// void	ft_lstclear(t_list **lst, void (*del)(void*));
// void	ft_lstadd_front(t_list **lst, t_list *new);
// void	ft_lstadd_back(t_list **lst, t_list *new);
// void	ft_lstiter(t_list *lst, void (*f)(void*));

// char	*ft_strcat(char *dest, const char *src);
// char	*ft_strdup(const char *s);
// char	*ft_strchr(const char *s, int c);
// char	*ft_strrchr(const char *s, int c);
// char	*ft_strncpy(char *dest, const char *src, size_t n);
// char	*ft_strcpy(char *destination, const char *source);
// char	*ft_strnstr(const char *big, const char *little, size_t len);
// char	*ft_itoa(int n);
// char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
// char	*ft_substr(char const *s, unsigned int start, size_t len);
// char	*ft_strtrim(char const *s1, char const *set);
// char	*ft_strjoin(char const *s1, char const *s2);
// char	**ft_split(char const *s, char c);

#endif
