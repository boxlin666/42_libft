#include<string.h>
char* ft_strtrim(char const *s)
{
    size_t i;
    size_t j;
    size_t k;
    char* str;

    i = 0;
    j = 0;
    k = 0;
    while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
        i++;
    while (s[j])
        j++;
    while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
        j--;
    if (j < i)
        return (str = (char*)malloc(1));
    str = (char*)malloc(j - i + 2);
    if (!str)
        return (NULL);
    while (i <= j)
        str[k++] = s[i++];
    str[k] = '\0';
    return (str);
}