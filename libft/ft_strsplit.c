/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:25:27 by bgian             #+#    #+#             */
/*   Updated: 2019/09/25 19:32:45 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				get_n_words(char const *s, char c)
{
	int	n;

	if (!s)
		return (0);
	n = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == 0))
			n++;
		s++;
	}
	return (n);
}

static const char		*start_of_next(const char *s, char sep)
{
	while (*s == sep)
		s++;
	return (s);
}

static size_t			len_of_next(const char *src, char sep)
{
	size_t	len;

	len = 0;
	while (*src != sep && *src != 0)
	{
		src++;
		len++;
	}
	return (len);
}

static void				avoid_leaks(char **res, int nlinks)
{
	while (nlinks > 0)
		free(res[nlinks--]);
	free(res);
}

char					**ft_strsplit(char const *s, char c)
{
	int		n_words;
	char	**res;
	size_t	len;
	int		i;

	i = 0;
	n_words = get_n_words(s, c);
	res = (char **)malloc(sizeof(char *) * (n_words + 1));
	if (!res)
		return (0);
	res[n_words] = 0;
	while (i < n_words)
	{
		s = start_of_next(s, c);
		len = len_of_next(s, c);
		res[i++] = ft_strsub(s, 0, len);
		if (!res[i - 1])
		{
			avoid_leaks(res, i - 2);
			return (0);
		}
		s += len;
	}
	return (res);
}
