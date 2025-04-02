/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <boxlin666@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:20:59 by helin             #+#    #+#             */
/*   Updated: 2025/04/02 10:25:53 by helin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<string.h>

void *ft_memset(void *b, int c, size_t len)
{
    unsigned char *p = b;
    while (len--)
        *p++ = (unsigned char)c;
    return b;
}
