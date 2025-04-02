/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <boxlin666@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:22:44 by helin             #+#    #+#             */
/*   Updated: 2025/04/02 10:30:36 by helin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<string.h>
#include"libft.h"

char *ft_strrchr(const char *s, int c)
{
    size_t i;

    i = ft_strlen(s);
    while (i > 0)
    {
        if (s[i] == c)
            return ((char *)&s[i]);
        i--;
    }
    if (s[i] == c)
        return ((char *)&s[i]);
    return (NULL);
}
