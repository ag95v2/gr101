/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxval_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 03:24:25 by dpenney           #+#    #+#             */
/*   Updated: 2019/10/25 03:36:05 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  Maximal value of integer array
*/

int		ft_maxval_int(int *a, unsigned int len)
{
	int	max;

	max = a[len - 1];
	while (len--)
	{
		if (a[len] > max)
			max = a[len];
	}
	return (max);
}
