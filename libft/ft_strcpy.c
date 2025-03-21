#include<string.h>
void *ft_strcpy(void *dest, const void *src)
{
    char *d = dest;
    const char *s = src;

    while (*s)
    {
        *d = *s;
        d++;
        s++;
    }
    *d = '\0';
    return dest;
}