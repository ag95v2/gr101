/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_unescaped.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:50:41 by bgian             #+#    #+#             */
/*   Updated: 2020/01/24 13:52:16 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Calculate ENDS of words
*/

static int				get_n_words(char const *s, char sep, char escape)
{
	int			n;
	const char	*start;

	start = s;
	if (!s)
		return (0);
	n = 0;
	while (*s)
	{
		if (ft_is_part_of_word(start, s, sep, escape) &&
			!ft_is_part_of_word(start, s + 1, sep, escape))
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

static size_t			len_of_next(const char *src, char sep, char escape)
{
	size_t		len;
	const char	*start;

	start = src;
	len = 0;
	while (ft_is_part_of_word(start, src, sep, escape))
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

char					**ft_strsplit_unescaped(char const *s, char c,\
		char escape)
{
	int		n_words;
	char	**res;
	size_t	len;
	int		i;

	i = 0;
	n_words = get_n_words(s, c, escape);
	res = (char **)malloc(sizeof(char *) * (n_words + 1));
	if (!res)
		return (0);
	res[n_words] = 0;
	while (i < n_words)
	{
		s = start_of_next(s, c);
		len = len_of_next(s, c, escape);
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
