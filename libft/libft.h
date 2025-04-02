#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdint.h>

// String functions
char    *ft_strcat(char *dest, const char *src);
char    *ft_strchr(const char *s, int c);
int     ft_strcmp(const char *s1, const char *s2);
char    *ft_strcpy(char *dest, const char *src);
size_t  ft_strlen(const char *s);
char    *ft_strdup(const char *s);
char    *ft_strncat(char *dest, const char *src, size_t n);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
char    *ft_strncpy(char *dest, const char *src, size_t n);
char    *ft_strstr(const char *haystack, const char *needle);

// Memory functions
void    *ft_memalloc(size_t size);
void    *ft_memcpy(void *dest, const void *src, size_t n);
void    *ft_memset(void *s, int c, size_t len);
void    ft_memdel(void **ap);

// Character checks
int     ft_isalpha(int c);
int     ft_isdigit(int c);
int     ft_isalnum(int c);
int     ft_isascii(int c);
int     ft_isprint(int c);

// Other utility functions
void    ft_bzero(void *s, size_t len);
int     ft_atoi(const char *str);
void    ft_putnbr(int n);
void    ft_putchar(char c);
void    ft_putstr(const char *s);
void    ft_putendl(const char *s);
void    ft_putchar_fd(char c, int fd);
void    ft_putstr_fd(const char *s, int fd);
void    ft_putendl_fd(const char *s, int fd);
void    ft_putnbr_fd(int n, int fd);

// String manipulation functions
char    *ft_strjoin(const char *s1, const char *s2);
char    *ft_strtrim(const char *s);
char    *ft_strsub(const char *s, unsigned int start, size_t len);
char    **ft_strsplit(const char *s, char c);

// Memory management functions
void    *ft_memmove(void *dest, const void *src, size_t len);
void    ft_strdel(char **as);
void    ft_striter(char *s, void (*f)(char *));
void    ft_striteri(char *s, void (*f)(unsigned int, char *));
char    *ft_strmap(const char *s, char (*f)(char));
char    *ft_strmapi(const char *s, char (*f)(unsigned int, char));

// Conversion functions
char    *ft_itoa(int n);
int     ft_tolower(int c);
int     ft_toupper(int c);

// Additional utility functions
int     ft_strnequ(const char *s1, const char *s2, size_t n);
char    *ft_strnew(size_t size);
char    *ft_strnstr(const char *haystack, const char *needle, size_t len);
void    ft_strclr(char *s);
void    ft_striter(char *s, void (*f)(char *));
#endif
