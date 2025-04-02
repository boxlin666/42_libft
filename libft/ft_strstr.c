/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <boxlin666@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:22:52 by helin             #+#    #+#             */
/*   Updated: 2025/04/02 10:30:48 by helin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<string.h>
#include"libft.h"

char *ft_strstr(const char *haystack, const char *needle)
{
    size_t i;
    size_t j;
    size_t needle_len;

    i = 0;
    j = 0;
    needle_len = ft_strlen(needle);
    if (needle_len == 0)
        return ((char *)haystack);
    while (haystack[i] != '\0')
    {
        if (haystack[i] == needle[j])
        {
            while (haystack[i + j] == needle[j] && needle[j] != '\0')
                j++;
            if (j == needle_len)
                return ((char *)&haystack[i]);
            j = 0;
        }
        i++;
    }
    return (NULL);
}
