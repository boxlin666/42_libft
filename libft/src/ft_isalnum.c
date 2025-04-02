/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <boxlin666@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:20:17 by helin             #+#    #+#             */
/*   Updated: 2025/04/02 10:24:45 by helin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_isalpha(int c);
int ft_isdigit(int c);

int ft_isalnum(int c)
{
    return (ft_isalpha(c) || ft_isdigit(c));
}
