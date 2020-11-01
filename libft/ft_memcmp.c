/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:37:23 by bgian             #+#    #+#             */
/*   Updated: 2019/09/25 14:16:53 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n && *((char *)s1++) == *((char *)s2++) && n--)
		;
	s1 -= 1;
	s2 -= 1;
	return (n ? (int)(*((unsigned char *)s1) - *((unsigned char *)s2)) : 0);
}

/*
** When differing bytes are treated as unsigned char, '\200' is > '0'
** (decimal of '\200' is 128 when treated as unsigned char and -128 when
** treated as signed char).
** That is why library implementation differs from man. See tests.
*/
