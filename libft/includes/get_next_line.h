/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 20:18:19 by bgian             #+#    #+#             */
/*   Updated: 2019/10/11 18:45:19 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <stdlib.h>
# include <errno.h>

# define MAX_OPEN_FILES 1024

# ifndef BUFF_SIZE
#  define BUFF_SIZE 1000
# endif

/*
** Max depth of binary tree, can be from 1 to 64
*/

# ifndef DEPTH
#  define DEPTH 14
# endif

typedef struct	s_unread_buff
{
	char		*data;
	int			pos;
	int			nbytes;
	int			eof;
	int			io_err;
	int			nl_found;
}				t_unread_buff;

int				get_next_line(const int fd, char **line);

#endif
