/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 14:36:09 by dcastro-          #+#    #+#             */
/*   Updated: 2017/07/17 20:23:41 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	int	get_width(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static	int	first_check(char *line)
{
	int		i;
	int		w;
	char	**tmp;

	i = 0;
	while (line[i])
	{
		if ((ft_isalpha(line[i])))
			return (0);
		if (line[i] == '-' && (!(ft_isdigit(line[i + 1]))))
			return (0);
		i++;
	}
	if (!(tmp = ft_strsplit(line, ' ')))
		return (0);
	if ((!(w = get_width(tmp))))
		return (0);
	free(tmp);
	return (w);
}

static	int	next_check(char *line)
{
	int		i;
	int		w2;
	char	**tmp;

	i = -1;
	while (line[++i])
	{
		if ((ft_isalpha(line[i])))
			return (0);
		if (line[i] == '-' && (!(ft_isdigit(line[i + 1]))))
			return (0);
	}
	if (!(tmp = ft_strsplit(line, ' ')))
		return (0);
	if (!(w2 = get_width(tmp)))
		return (0);
	free(tmp);
	return (w2);
}

static	int	check_values(int fd, t_env *e)
{
	int		w_first;
	int		w;
	char	*line;

	line = NULL;
	if (get_next_line(fd, &line))
	{
		if ((w_first = first_check(line)) == 0)
			return (0);
		e->height++;
		ft_strdel(&line);
	}
	else
		return (0);
	while (get_next_line(fd, &line))
	{
		if ((w = next_check(line)) != w_first)
			return (0);
		e->height++;
		ft_strdel(&line);
	}
	e->width = w;
	close(fd);
	return (1);
}

int			check_file(char *av, t_env *e)
{
	int fd;

	if (!(ft_strstr(av, ".fdf")))
		error_msg("Invalid Filename");
	if (!av)
		error_msg("no argument");
	if ((fd = open(av, O_RDONLY)) < 0)
		error_msg("bad fd");
	if (!(check_values(fd, e)))
		error_msg("bad file values");
	return (1);
}
