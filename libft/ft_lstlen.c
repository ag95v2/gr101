/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:57:11 by bgian             #+#    #+#             */
/*   Updated: 2020/01/24 13:57:16 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstlen(t_list *l)
{
	int	i;

	if (!l)
		return (0);
	i = 1;
	while (l->next)
	{
		l = l->next;
		i++;
	}
	return (i);
}
