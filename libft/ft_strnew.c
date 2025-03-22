#include<string.h>
char* ft_strnew(size_t size)
{
    char* str = (char*)malloc(size + 1);
    if (str == NULL)
        return (NULL);
    int i = 0;
    while (i < size)
    {
        str[i] = '\0';
        i++;
    }
    str[size] = '\0';
    return (str);
}