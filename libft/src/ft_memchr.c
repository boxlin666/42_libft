/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <boxlin666@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:20:44 by helin             #+#    #+#             */
/*   Updated: 2025/04/02 10:25:37 by helin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<string.h>

void *memchr(const void *s, int c, size_t n)
{
    unsigned char *s_ptr;
    size_t i;

    s_ptr = (unsigned char *)s;
    i = 0;
    while (i < n)
    {
        if (s_ptr[i] == (unsigned char)c)
            return (s_ptr + i);
        i++;
    }
    return (NULL);
}
