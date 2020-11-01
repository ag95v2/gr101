/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:55:09 by dpenney           #+#    #+#             */
/*   Updated: 2020/01/24 17:25:48 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
**	Return appropritate action according to spec if such exists else 0
*/

t_conv_f	*find_action(t_spec spec)
{
	static t_conv_f	actions[] = {{"di", &w_itoa_b10, &int_extractor, 1},\
				{"u", &w_itoa_b10u, &int_extractor, 1},\
				{"o", &w_itoa_b8, &int_extractor, 1},\
				{"xp", &w_itoa_x, &int_extractor, 1},\
				{"X", &w_itoa_xx, &int_extractor, 1},\
				{"f", &w_ftoa, &float_extractor, 1},\
				{"c", &w_ctoa, &char_extractor, 1},\
				{"s", &w_stoa, &str_extractor, 0},\
				{"%", &w_percent, &dummy_extractor, 0},\
				{0, 0, 0, 0}};
	static t_conv_f	action;
	int				i;

	i = 0;
	while ((action = actions[i++]).specifiers)
		if (ft_strchr(action.specifiers, spec.conv))
			return (&action);
	return (0);
}
