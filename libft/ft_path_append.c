/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_append.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:56:51 by bgian             #+#    #+#             */
/*   Updated: 2020/01/24 13:56:54 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_path_append(char *path, char *name)
{
	char	*new;
	char	*start;

	new = ft_memalloc(ft_strlen(path) + ft_strlen(name) + 2);
	if (!new)
		return (NULL);
	start = new;
	while ((*new++ = *path++))
		;
	new--;
	if (*(path - 1) != '/')
		*new++ = '/';
	ft_strcpy(new, name[0] == '/' ? name + 1 : name);
	return (start);
}
