/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 18:50:52 by bgian             #+#    #+#             */
/*   Updated: 2019/12/24 20:49:01 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			str_rev(char *s)
{
	int		len;
	int		i;
	char	tmp;

	i = 0;
	len = ft_strlen(s);
	while (i < (len - i - 1))
	{
		tmp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = tmp;
		i++;
	}
}

static int			my_abs(int n)
{
	return (n > 0 ? n : -1 * n);
}

static void			ft_itoa_stack(int n, char *s)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		s[0] = '-';
		i++;
	}
	if (n == 0)
	{
		s[0] = '0';
		s[1] = 0;
		return ;
	}
	while (n)
	{
		s[i++] = my_abs(n % 10) + '0';
		n = n / 10;
	}
	s[i] = 0;
	str_rev((s[0] == '-') ? s + 1 : s);
}

void				ft_putnbr(int n)
{
	char	s[12];
	int		i;

	i = 0;
	while (i < 12)
		s[i++] = 0;
	ft_itoa_stack(n, s);
	ft_putstr(s);
}
