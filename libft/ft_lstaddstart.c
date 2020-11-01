/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddstart.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:57:33 by bgian             #+#    #+#             */
/*   Updated: 2020/01/24 13:57:35 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Create new list with new content
** Return pointer to start
*/

t_list	*ft_lstappend(t_list *lst, void const *content, size_t content_size)
{
	t_list	*new;
	t_list	*tmp;

	if (!content_size || !content || !(new = ft_lstnew(content, content_size)))
		return (lst);
	if (!lst)
		return (new);
	tmp = lst;
	while (lst->next)
		lst = lst->next;
	lst->next = new;
	return (tmp);
}
