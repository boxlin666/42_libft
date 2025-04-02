/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <boxlin666@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:21:27 by helin             #+#    #+#             */
/*   Updated: 2025/04/02 10:26:52 by helin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<string.h>
#include"libft.h"

void *ft_strcpy(void *dest, const void *src)
{
    char *d = dest;
    const char *s = src;

    while (*s)
    {
        *d = *s;
        d++;
        s++;
    }
    *d = '\0';
    return dest;
}
