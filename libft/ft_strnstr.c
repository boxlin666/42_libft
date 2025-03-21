#include<string.h>
char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t i;
    size_t j;
    size_t needle_len;

    i = 0;
    j = 0;
    needle_len = ft_strlen(needle);
    if (needle_len == 0)
        return ((char *)haystack);
    while (haystack[i] != '\0' && i < len)
    {
        if (haystack[i] == needle[j])
        {
            while (haystack[i + j] == needle[j] && needle[j] != '\0' && i + j < len)
                j++;
            if (j == needle_len)
                return ((char *)&haystack[i]);
            j = 0;
        }
        i++;
    }
    return (NULL);
}