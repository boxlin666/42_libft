/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <boxlin666@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:22:39 by helin             #+#    #+#             */
/*   Updated: 2025/04/02 12:51:33 by helin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<string.h>
#include"libft.h"

char* ft_strnew(size_t size)
{
    char* str = (char*)malloc(size + 1);
    if (str == NULL)
        return (NULL);
    size_t i = 0;
    while (i < size)
    {
        str[i] = '\0';
        i++;
    }
    str[size] = '\0';
    return (str);
}
