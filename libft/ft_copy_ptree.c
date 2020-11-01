/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_ptree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:57:44 by bgian             #+#    #+#             */
/*   Updated: 2020/01/24 13:57:46 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ptree.h"

t_ptree				*copy_ptree(t_ptree *tree)
{
	int			i;
	t_ptree		*copy;

	if (!tree)
		return (NULL);
	if (!(copy = new_tree()))
		return (NULL);
	if (tree->value && !(copy->value = ft_strdup(tree->value)))
	{
		free(copy);
		return (NULL);
	}
	i = -1;
	while (++i < N_CHILDREN)
	{
		if (tree->child[i] && !(copy->child[i] = copy_ptree(tree->child[i])))
		{
			del_tree(copy);
			return (NULL);
		}
	}
	return (copy);
}
