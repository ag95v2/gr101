/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:43:56 by bgian             #+#    #+#             */
/*   Updated: 2019/09/25 19:42:48 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*add_to_end(t_list *l, t_list *new)
{
	t_list	*start;

	if (!l)
		return (new);
	start = l;
	while (l->next)
		l = l->next;
	l->next = new;
	return (start);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	new = 0;
	while (lst)
	{
		new = add_to_end(new, f(lst));
		lst = lst->next;
	}
	return (new);
}
