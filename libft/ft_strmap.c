/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:39:15 by bgian             #+#    #+#             */
/*   Updated: 2019/09/25 18:20:33 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	int		i;

	i = 0;
	new = ft_strnew(ft_strlen(s) + 1);
	if (!new)
		return (0);
	while (s[i])
	{
		new[i] = f(s[i]);
		i++;
	}
	return (new);
}
