/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 14:36:09 by dcastro-          #+#    #+#             */
/*   Updated: 2017/07/12 23:02:41 by dcastro-         ###   ########.fr       */
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

static int check_values(int fd)
{
	int w;
	int w2;
	int i;
	char **tmp;
	char *line;

	w = 0;
	w2 = 0;
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
		if ((!(w = get_width(tmp))))
			return (0);
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
		if ((w2 = get_width(tmp)) != w)
			return (0);
		free(tmp);
		ft_strdel(&line);
	}
	return (1);
}
int check_file(char *av)
{
	int fd;

	if (!av)
		return (0);
	if ((fd = open(av, O_RDONLY)) < 0)
		return (0);
	if (!(check_values(fd)))
		return (0);
	return (1);
}
