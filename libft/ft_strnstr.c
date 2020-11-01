/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:29:00 by bgian             #+#    #+#             */
/*   Updated: 2019/09/25 17:09:41 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*f_occ;

	f_occ = ft_strstr(haystack, needle);
	return ((f_occ + ft_strlen(needle) > haystack + len || !f_occ) ? \
			NULL : f_occ);
}
