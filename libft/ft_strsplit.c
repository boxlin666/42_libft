#include<string.h>
#include<stdlib.h>

char **ft_strsplit(char const *s, char c)
{
    char **tab;
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    if (!s)
        return (NULL);
    if (!(tab = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1))))
        return (NULL);
    while (s[i])
    {
        while (s[i] == c)
            i++;
        if (s[i])
        {
            k = 0;
            if (!(tab[j] = (char *)malloc(sizeof(char) * (ft_word_len(s, c, i) + 1))))
                return (NULL);
            while (s[i] && s[i] != c)
                tab[j][k++] = s[i++];
            tab[j++][k] = '\0';
        }
    }
    tab[j] = NULL;
    return (tab);
}