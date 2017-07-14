/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 14:36:09 by dcastro-          #+#    #+#             */
/*   Updated: 2017/07/13 19:37:11 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// static int line_check(char *s)
// {
// 	int i;

// 	i = 0;
// 	printf("here: %s\n", s);
// 	while (s[i])
// 	{
// 		if ((ft_isalpha(s[i])))
// 			return (0);
// 		if (s[i] == '-' &&  ((s[ + 1] <= '0' || s[i + 1] >= '9')))
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

static int get_width(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int check_values(int fd, t_env *e)
{
	int w_first;
	int w;
	int i;
	char **tmp;
	char *line;

	w_first = 0;
	w = 0;
	line = NULL;
	i = 0;
	if (get_next_line(fd, &line))
	{
		while (line[i])
		{	
			if ((ft_isalpha(line[i])))
				return (0);
			if (line[i] == '-' &&  ((line[ + 1] <= '0' || line[i + 1] >= '9')))
				return (0);
			i++;
		}
		if (!(tmp = ft_strsplit(line, ' ')))
			return (0);
		if ((!(w_first = get_width(tmp))))
			return (0);
		e->height++;
		ft_strdel(&line);
		free(tmp);
	}
	else
		return (0);
	while (get_next_line(fd, &line))
	{
		i = 0;
		while (line[i])
		{	
			if ((ft_isalpha(line[i])))
				return (0);
			if (line[i] == '-' &&  ((line[ + 1] <= '0' || line[i + 1] >= '9')))
				return (0);
			i++;
		}
		if (!(tmp = ft_strsplit(line, ' ')))
			return (0);
		if ((w = get_width(tmp)) != w_first)
			return (0);
		else
			e->width = w;
		e->height++;
		free(tmp);
		ft_strdel(&line);
	}
	close(fd);
	return (1);
}
int check_file(char *av, t_env *e)
{
	int fd;

	if (!av)
		return (0);
	if ((fd = open(av, O_RDONLY)) < 0)
		return (0);
	if (!(check_values(fd, e)))
		return (0);
	return (1);
}
