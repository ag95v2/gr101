/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minval_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 03:36:47 by dpenney           #+#    #+#             */
/*   Updated: 2019/10/25 03:37:06 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  Minimal value of integer array
*/

int		ft_minval_int(int *a, unsigned int len)
{
	int	min;

	min = a[len - 1];
	while (len--)
	{
		if (a[len] < min)
			min = a[len];
	}
	return (min);
}
