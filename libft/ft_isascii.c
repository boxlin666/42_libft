
/**
 * ft_isascii - Checks if a character is an ASCII character.
 * @c: The character to check.
 *
 * Return: 1 if the character is an ASCII character (0-127),
 *         0 otherwise.
 */
int ft_isascii(int c)
{
    return (c >= 0 && c <= 127);
}