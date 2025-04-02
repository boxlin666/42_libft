/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <boxlin666@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:22:21 by helin             #+#    #+#             */
/*   Updated: 2025/04/02 10:30:06 by helin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<string.h>
#include<stdlib.h>
#include"libft.h"

char* ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *new;
    size_t i;

    if (!s || !f)
        return (NULL);
    new = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
    if (!new)
        return (NULL);
    i = 0;
    while (s[i])
    {
        new[i] = f(i, s[i]);
        i++;
    }
    new[i] = '\0';
    return (new);
}
