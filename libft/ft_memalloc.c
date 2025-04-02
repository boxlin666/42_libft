/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <boxlin666@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:20:37 by helin             #+#    #+#             */
/*   Updated: 2025/04/02 10:25:29 by helin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<string.h>
#include<stdlib.h>
#include "libft.h"

void *ft_memset(void *b, int c, size_t len);

void *ft_memalloc(size_t size)
{
    void *ptr;

    ptr = malloc(size);
    if (ptr == NULL)
        return (NULL);
    ft_memset(ptr, 0, size);
    return (ptr);
}
