/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 03:25:17 by dpenney           #+#    #+#             */
/*   Updated: 2019/10/25 03:25:19 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  Return pointer to minimal element of array
*/

int	*ft_min_int(int *arr, int len)
{
	int	*min;

	min = arr;
	while (len--)
	{
		if (*(arr + len) < *min)
			min = arr + len;
	}
	return (min);
}
