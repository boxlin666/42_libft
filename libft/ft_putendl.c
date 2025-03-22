#include<unistd.h>

void    ft_putendl(char *str)
{
    while (*str)
        write(1, str++, 1);
    write(1, "\n", 1);
}