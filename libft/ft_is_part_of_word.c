/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_part_of_word.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:59:33 by bgian             #+#    #+#             */
/*   Updated: 2020/01/24 13:59:44 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return 1 if position is escaped separator or not separator
*/

int				ft_is_part_of_word(const char *start,\
		const char *position,\
		char sep,\
		char escape)
{
	if (!*position)
		return (0);
	if (*position != sep)
		return (1);
	if (*position == sep && ft_is_escaped(start, position, escape))
		return (1);
	return (0);
}
