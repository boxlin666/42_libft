/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <boxlin666@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:20:33 by helin             #+#    #+#             */
/*   Updated: 2025/04/02 10:25:26 by helin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdlib.h>

void ft_fillstr(int n, char* str, int len)
{
    if (n < 0)
        str[0] = '-';
    if (n == 0)
        str[0] = '0';
    while (n)    
    {
        if (n < 0)
            str[--len] = -(n % 10) + '0';
        else
            str[--len] = n % 10 + '0';
        n /= 10;
    }
}

char* ft_itoa(int n)
{
    char* str;
    int len;
    int temp;

    len = 1;
    temp = n;
    while (temp /= 10)
        len++;
    if (n < 0)
        len++;
    if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
        return (NULL);
    str[len] = '\0';
    ft_fillstr(n, str, len);
    return (str);
}
