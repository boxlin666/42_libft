/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <helin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:10:34 by helin             #+#    #+#             */
/*   Updated: 2025/04/05 15:11:12 by helin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_list;
	t_list *current;

	if (!lst || !f)
		return (NULL);
	new_list = f(lst);
	if (!new_list)
		return (NULL);
	current = new_list;
	while (lst->next)
	{
		lst = lst->next;
		current->next = f(lst);
		if (!current->next)
			return (NULL);
		current = current->next;
	}
	return (new_list);
}