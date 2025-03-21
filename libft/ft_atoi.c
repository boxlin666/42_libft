int ft_isspace(int c)
{
    return (c == ' ' || c == '\t' || c == '\n' ||
            c == '\v' || c == '\f' || c == '\r');
}

int ft_atoi(const char *str)
{
    int sign = 1;
    int result = 0;

    // Skip whitespace
    while (*str && ft_isspace((unsigned char)*str))
        str++;

    // Handle sign
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }

    // Convert digits to integer
    while (*str && isdigit((unsigned char)*str))
    {
        result = result * 10 + (*str - '0');
        str++;
    }

    return result * sign;
}