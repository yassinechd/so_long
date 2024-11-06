/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachadla <yachadla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:03:33 by yass              #+#    #+#             */
/*   Updated: 2024/11/05 23:54:02 by yachadla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>// write, t_size
# include <stdlib.h>// malloc
# include <stdio.h>// printf pour tester fonction 
# include <string.h> // pour tester fonction
# include <stdarg.h>
#include <fcntl.h>
#include <stdlib.h>

# define BUFFER_SIZE 1000

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_split
{
	char			**tab;
	size_t			len;
	size_t			i;
}					t_split;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi( const char *str);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t nelem, size_t elsize);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s1, char const *set);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

//printf
int		ft_printf(const char *str, ...);
int		ft_arg_count(const char	*str);
int		ft_dispatch(char c, va_list args);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int nbr);
int		ft_putnbr_unsigned(unsigned int nbr);
void	ft_recur_hexa(int nbr, char format);
int		ft_putnbr_hexa2(int nbr);
int		ft_putnbr_hexa(unsigned int nbr, char format);
int		ft_aff_point(unsigned long long nbr);
int		ft_print_ptr2(unsigned long long ptr);

//gnl
char			*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char *s2);
char		*ft_strdup_gnl(char *s);
char	*ft_substr_gnl(char *s, unsigned int start, size_t len);
char	*ft_strchr_gnl(const char *s, int c);
void *ft_free_gnl(char *str);


#endif
