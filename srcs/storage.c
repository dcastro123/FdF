/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 13:09:02 by dcastro-          #+#    #+#             */
/*   Updated: 2017/07/13 22:16:59 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	find_zcoord(t_env *e, int y)
{
	printf("?????\n");
	int i;
	int j;
	int k;

	j = -1;
	k = -1;
	i = -1;
	while (++i < e->width)
	{
		if (e->z_max > e->store_arr[y][i])
			e->z_max = e->store_arr[y][i];
		else
			e_max = z_max;
		if (e->z_min < e->store_arr[y][i])
	}
	return (tmp);
}

void	store_points(t_env *e, char *av)
{
	char **tmp;
	char *line;
	int i;
	int j;
	int k;
	int fd;

	i = 0;
	line = NULL;
	if ((fd = open(av, O_RDONLY)) < 0)
		return (ft_putendl("bad file"));
	if (!(e->zstore_arr = (int**)malloc(sizeof(int*) * (e->height + 1))))
		return (ft_putendl("bad malloc"));
	while (get_next_line(fd, &line))
	{
		k = -1;
		j = -1;
		if (!(tmp = ft_strsplit(line, ' ')))
			return (ft_putendl("bad lines"));
		e->store_arr[i] = (int*)malloc(sizeof(int) * (e->width + 1));
		while (++k < e->width)
			e->store_arr[i][k] = ft_atoi(&tmp[i][k]);
		while (++j < e->width)
		{
			if (e->z_max > e->store_arr[i][j])
				e->z_max = e->store_arr[i][j];
			else
				e_max = z_max;
			if (e->z_min < e->store_arr[j][j])
				e->z_min = e->store_arr[i][j];
			else
				e->z_min = e->z_min;
		}
		i++;
		ft_strdel(&line);
		free(tmp);
	}
	e->zstore_arr[i] = 0;
	i = 0;
	while (e->zstore_arr[i])
	{
		k = 0;
		while (e->zstore_arr[k])
		{
			printf("char: [%d][%d]: %d\n", i, k, e->zstore_arr[i][k]);
			k++;
		}
		i++;
	}
	close(fd);
}