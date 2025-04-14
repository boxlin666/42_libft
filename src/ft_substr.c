/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <helin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:22:55 by helin             #+#    #+#             */
/*   Updated: 2025/04/13 09:42:48 by helin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	src_len;

	if (!s)
		return (NULL);
	src_len = strlen(s);
	if (start >= src_len)
		len = 0;
	else if (start + len > src_len)
		len = src_len - start;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	memcpy(sub, s + start, len);
	sub[len] = '\0';
	return (sub);
}
