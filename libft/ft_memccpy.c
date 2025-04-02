/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <boxlin666@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:20:40 by helin             #+#    #+#             */
/*   Updated: 2025/04/02 10:25:32 by helin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
    unsigned char *dest_ptr;
    unsigned char *src_ptr;
    size_t i;

    dest_ptr = (unsigned char *)dest;
    src_ptr = (unsigned char *)src;
    i = 0;
    while (i < n)
    {
        dest_ptr[i] = src_ptr[i];
        if (src_ptr[i] == (unsigned char)c)
            return (dest_ptr + i + 1);
        i++;
    }
    return (NULL);
}
