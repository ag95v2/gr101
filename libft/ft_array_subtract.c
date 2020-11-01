/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_subtract.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 03:11:39 by dpenney           #+#    #+#             */
/*   Updated: 2019/10/25 03:46:35 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Subtract a number from integer array
**  If in_place, modify existing object else create new
*/

int	*ft_array_subtract(int *arr, unsigned int len, int number, int in_place)
{
	int				*res;
	unsigned int	i;

	res = in_place ? arr : (int *)malloc(sizeof(int) * len);
	if (!res)
		return (0);
	i = 0;
	while (i < len)
	{
		res[i] = arr[i] - number;
		i++;
	}
	return (res);
}
