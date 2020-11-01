/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 03:37:50 by dpenney           #+#    #+#             */
/*   Updated: 2019/10/25 03:37:52 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Swap 2 non-overlapping objects
*/

void	ft_swap(void *a, void *b, size_t len)
{
	char	tmp;

	while (len--)
	{
		tmp = *(char *)a;
		*(char *)a = *(char *)b;
		*(char *)b = tmp;
	}
}
