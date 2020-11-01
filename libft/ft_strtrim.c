/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:11:24 by bgian             #+#    #+#             */
/*   Updated: 2019/09/23 16:36:10 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*end_of_text;

	while (*s && ft_isspace(*s))
		s++;
	end_of_text = (char *)s;
	while (*end_of_text)
		end_of_text++;
	while (ft_isspace(*(--end_of_text)))
		;
	return (ft_strsub(s, 0, (end_of_text >= s ? end_of_text - s + 1 : 0)));
}
