/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 14:36:09 by dcastro-          #+#    #+#             */
/*   Updated: 2017/07/12 22:28:33 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int line_check(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if ((ft_isalpha(s[i])))
			return (0);
		if (s[i] == '-' &&  !ft_isdigit(s[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

static int get_width(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int check_values(int fd, char *line)
{
	int w;
	int w2;
	char **tmp;

	w = 0;
	w2 = 0;
	if (get_next_line(fd, &line))
	{
		if (!(line_check(line)))
			return (0);
		if (!(tmp = ft_strsplit(line, ' ')))
			return (0);
		if ((!(w = get_width(tmp))))
			return (0);
		ft_strdel(&line);
		free(tmp);
	}
	else
		return (0);
	while (get_next_line(fd, &line))
	{
		if (!(line_check(line)))
			return (0);
		if (!(tmp = ft_strsplit(line, ' ')))
			return (0);
		if ((w2 = get_width(tmp) != w))
			return (0);
		free(tmp);
		ft_strdel(&line);
	}
	return (1);
}
int check_file(char *av)
{
	int fd;
	char *line;

	line = NULL;
	if (!av)
		return (0);
	if ((fd = open(av, O_RDONLY)) < 0)
		return (0);
	if (!(check_values(fd, line)))
		return (0);
	return (1);
}
