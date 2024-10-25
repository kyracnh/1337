#ifndef LIBFT_H
#define LIBFT_H

#include <stdio.h>

int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
size_t	ft_strlen(const char *str);
int	ft_toupper(int c);
int	ft_tolower(int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t  strlcat(char *dest, const char *src, size_t destsize);
int ft_strncmp(const char *s1, const char *s2, size_t n);
char    *ft_strchr(const char *str, int c);
char    *ft_strrchr(const char *str, int c);
char    *ft_strnstr(const char *haystack, const char *needle, size_t len);
int    ft_atoi(const char *str);
void    ft_bzero(void *s, size_t n);

#endif
