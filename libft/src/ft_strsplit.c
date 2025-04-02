/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <boxlin666@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:22:48 by helin             #+#    #+#             */
/*   Updated: 2025/04/02 12:52:27 by helin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<string.h>
#include<stdlib.h>
#include"libft.h"

static int ft_count_words(char const *s, char c)
{
    int count;
    int i;

    count = 0;
    i = 0;
    while (s[i])
    {
        while (s[i] == c)
            i++;
        if (s[i] && s[i] != c)
        {
            count++;
            while (s[i] && s[i] != c)
                i++;
        }
    }
    return (count);
}

static int ft_word_len(char const *s, char c, int i)
{
    int len;

    len = 0;
    while (s[i] && s[i] != c)
    {
        len++;
        i++;
    }
    return (len);
}

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
