/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <helin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:22:58 by helin             #+#    #+#             */
/*   Updated: 2025/04/06 14:50:21 by helin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static int	ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char *ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);

	i = 0;
	while (ft_is_whitespace(s[i]))
		i++;

	j = strlen(s);
	while (j > i && ft_is_whitespace(s[j - 1]))
		j--;

	str = (char *)malloc(j - i + 1);
	if (!str)
		return (NULL);
	memcpy(str, s + i, j - i);
	str[j - i] = '\0';
	return (str);
}
