/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_escaped.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 14:00:06 by bgian             #+#    #+#             */
/*   Updated: 2020/01/24 14:02:08 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return 1 if before symbol string contains odd number of escape_chars
*/

int	ft_is_escaped(const char *start,\
		const char *symbol, char escape_char)
{
	int	n_escapes;

	n_escapes = 0;
	while (symbol != start && *(symbol - 1) == escape_char)
	{
		symbol--;
		n_escapes++;
	}
	return (n_escapes % 2);
}
