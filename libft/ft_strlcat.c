#include<string.h>
char *ft_strlcat(char *dest, const char *src, size_t size)
{
    size_t i;
    size_t j;
    size_t dest_len;
    size_t src_len;

    i = 0;
    j = 0;
    dest_len = ft_strlen(dest);
    src_len = ft_strlen(src);
    if (size <= dest_len)
        return (size + src_len);
    while (dest[i] != '\0')
        i++;
    while (src[j] != '\0' && i < size - 1)
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (dest_len + src_len);
}