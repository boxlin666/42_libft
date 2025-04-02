/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <boxlin666@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:21:33 by helin             #+#    #+#             */
/*   Updated: 2025/04/02 10:27:12 by helin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<string.h>
#include<stdlib.h>
#include"libft.h"

char *ft_strdup(const char *s)
{
    size_t len = ft_strlen(s);
    char *d = malloc(len + 1);
    if (d)
        ft_memcpy(d, s, len + 1);
    return d;
}
