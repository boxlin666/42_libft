
/**
 * ft_isalpha - Checks if a character is a letter in alphabet.
 * @c: The character to check.
 *
 * Return: 1 if the character is a letter (A-Z or a-z),
 *         0 otherwise.
 */
int ft_isalpha(int c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}