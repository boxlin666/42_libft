#include<string.h>
#include<stdlib.h>

char* ft_strsub(char const* s, unsigned int start, size_t len)
{
    char* str;
    size_t i;

    if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
        return (NULL);
    i = 0;
    while (i < len)
    {
        str[i] = s[start + i];
        i++;
    }
    str[i] = '\0';
    return (str);
}