/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:20:41 by bgian             #+#    #+#             */
/*   Updated: 2019/09/23 16:46:26 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*del_get_next(t_list *l, void (*del)(void *, size_t))
{
	t_list	*next;

	if (!l)
		return (0);
	next = l->next;
	ft_lstdelone(&l, del);
	return (next);
}

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*l;

	l = *alst;
	while ((l = del_get_next(l, del)))
		;
	*alst = 0;
}
