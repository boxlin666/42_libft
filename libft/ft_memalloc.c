#include<string.h>
#include<stdlib.h>
void *ft_memalloc(size_t size)
{
    void *ptr;

    ptr = malloc(size);
    if (ptr == NULL)
        return (NULL);
    memset(ptr, 0, size);
    return (ptr);
}