/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 03:39:47 by dpenney           #+#    #+#             */
/*   Updated: 2019/10/25 03:45:46 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  Return pointer to maximal element of array
*/

int	*ft_max_int(int *arr, int len)
{
	int	*max;

	max = arr;
	while (len--)
	{
		if (*(arr + len) > *max)
			max = arr + len;
	}
	return (max);
}
