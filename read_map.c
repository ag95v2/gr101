#include "libft.h"

/*
** Non-rectangular maps are not allowed yet
** Max, min height needed for colors;
** coords[x][y] = z 
*/

typedef struct s_map
{
	int width;
	int len;
	int min_height;
	int max_height;
	int ***coords;
} t_map;

static t_list *file_to_list(int fd)
{
	char	*s;
	int		status;
	t_list	*l;

	l = NULL;
	while ((status = get_next_line(fd, &s)) > 0)
	{
		ft_lstadd_data(*l, s, ft_strlen(s) + 1);
	}
	if (status == -1)
	{
		ft_printf("Could not read the file\n");
		exit(1);
	}
	if (ft_lstlen(l) < 1)
	{
		ft_printf("Empty map\n");
		exit(1);
	}
	return (l);
}

static int		is_number(char *s)
{
	if (!*s)
	{
		return (0);
	}
	while (*s)
	{
		if (!ft_isdigit(*s))
		{
			return (0);
		}
		s++;
	}
	return (1);
}

static int		count_numbers(const char *s)
{
	char **numbers;
	int	i;

	numbers = ft_strsplit(s, ' ');
	if (!numbers)
	{
		ft_printf("Format error at line '%s'\n", s);
		exit(1);
	}
	i = 0;
	while (*numbers)
	{
		if (!is_number(*numbers))
		{
			ft_printf("Format error at line '%s'\n", s);
			exit(1);
		}
		numbers++;
		i++;
	}
	return (i);
}

static int **new_empty_map(int width, int len)
{

}

t_map *read_map(int fd)
{
	t_map	*m;
	t_list	*l;

	m = malloc(sizeof(t_map));
	if (!m)
	{
		printf("No memory\n");
		exit(ENOMEM);	
	}
	l = file_to_list(fd);
	m.len = ft_lstlen(l);
	m.width = count_numbers((const char *)l->content);
	map->coords = malloc(sizeof(int *) * m.len);
	
}
