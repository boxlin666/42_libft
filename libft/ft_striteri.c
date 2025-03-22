void ft_striteri(char *s, void (*f)(unsigned int, char *))
{
    unsigned int i = 0;
    while (*s)
    {
        f(i, s);
        s++;
        i++;
    }
}