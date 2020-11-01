/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 03:25:41 by dpenney           #+#    #+#             */
/*   Updated: 2019/10/25 03:37:22 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  Just print an integer aray
*/

void	ft_print_array(int *a, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_putnbr(a[i]);
		ft_putstr(i < len - 1 ? ", " : "\n");
		i++;
	}
}
