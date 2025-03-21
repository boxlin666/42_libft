#include<string.h>
#include<stdlib.h>
char *ft_strdup(const char *s)
{
    size_t len = ft_strlen(s);
    char *d = malloc(len + 1);
    if (d)
        ft_memcpy(d, s, len + 1);
    return d;
}