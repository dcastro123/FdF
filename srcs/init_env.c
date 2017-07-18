/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 13:10:29 by dcastro-          #+#    #+#             */
/*   Updated: 2017/07/17 20:16:11 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			init_estruct(t_env *e)
{
	e->x_mid = 0;
	e->y_mid = 0;
	e->slope = 0;
	e->dist = 0;
	e->width = 0;
	e->height = 0;
	e->z_max = 0;
	e->z_min = 0;
	e->win_wmax = 0;
	e->win_hmax = 0;
	e->x1 = 0;
	e->x2 = 0;
	e->y1 = 0;
	e->y2 = 0;
	e->delta = 0;
}

void			init_pstruct(t_points *point)
{
	point->z = 0;
	point->x = 0;
	point->y = 0;
	point->z2 = 0;
}

static	void	find_values(t_env *e)
{
	if (e->width > e->height)
		e->dist = 700 / e->width;
	else if (e->height > e->width)
		e->dist = 700 / e->height;
	else if (e->height == e->width)
		e->dist = 700 / e->height;
	e->win_wmax = (e->width > e->height ? (900 + (e->width * e->dist))
			: (900 + (e->height * e->dist)));
	e->win_hmax = e->win_wmax - 300;
}

t_points		**store_cpoints(t_env *e)
{
	int			i;
	int			j;
	t_points	**point;

	if (!(point = (t_points**)malloc(sizeof(t_points*) * (e->height + 1))))
		return (NULL);
	i = -1;
	while (++i < e->height)
	{
		j = -1;
		if (!(point[i] = (t_points*)malloc(sizeof(t_points) * (e->width + 1))))
			return (NULL);
		while (++j < e->width)
		{
			point[i][j].x = (j - e->x_mid) * e->dist;
			point[i][j].y = (i - e->y_mid) * e->dist;
			point[i][j].z = e->store_arr[i][j] * 5;
		}
	}
	point[i] = 0;
	return (point);
}

void			setup_env(t_env *e)
{
	t_points point;

	init_pstruct(&point);
	find_values(e);
	e->x_mid = e->width / 2;
	e->y_mid = e->height / 2;
	e->point = store_cpoints(e);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->win_wmax, e->win_hmax, "42 FDF");
	rotate(e);
	translate(e);
}
