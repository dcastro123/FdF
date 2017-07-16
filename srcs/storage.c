/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 13:09:02 by dcastro-          #+#    #+#             */
/*   Updated: 2017/07/15 18:55:32 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	find_z(t_env *e, int y)
{
	int i;
	
	i = -1;
	while (++i < e->width)
	{
		if (e->z_max > e->store_arr[y][i])
			e->z_max = e->store_arr[y][i];
		else
			e->z_max = e->z_max;
		if (e->z_min < e->store_arr[y][i])
			e->z_min = e->store_arr[y][i];
		else
			e->z_min = e->z_min;
	}
}

static void zstore(t_env *e, char *line, int i)
{
	int k;
	char **tmp;

	k = -1;
	if (!(tmp = ft_strsplit(line, ' ')))
		return (ft_putendl("bad lines"));
	e->store_arr[i] = (int*)malloc(sizeof(int) * (e->width + 1));
	while (++k < e->width)
		e->store_arr[i][k] = ft_atoi(&tmp[k][0]);
	e->store_arr[i][k] = '\0';
	free(tmp);
}

void	store_points(t_env *e, char *av)
{
	char *line;
	int i;
	int fd;

	i = 0;
	line = NULL;
	if ((fd = open(av, O_RDONLY)) < 0)
		return (ft_putendl("bad file"));
	if (!(e->store_arr = (int**)malloc(sizeof(int*) * (e->height + 1))))
		return (ft_putendl("bad malloc"));
	while (get_next_line(fd, &line))
	{
		zstore(e, line, i);
		find_z(e, i);
		i++;
		ft_strdel(&line);
	}
	e->store_arr[i] = 0;
	close(fd);
}