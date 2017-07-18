/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 22:26:37 by dcastro-          #+#    #+#             */
/*   Updated: 2017/07/17 05:00:08 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	translate(t_env *e)
{
	int a;
	int b;

	a = -1;
	while (++a < e->height)
	{
		b = -1;
		while (++b < e->width)
		{
			e->point[a][b].x += e->win_wmax / 2;
			e->point[a][b].y += e->win_hmax / 2;
		}
	}
}

void	set_right(t_env *e, int i, int j)
{
	if (j + 1 < e->width)
	{
		e->x1 = round(e->point[i][j].x);
		e->x2 = round(e->point[i][j + 1].x);
		e->y1 = round(e->point[i][j].y);
		e->y2 = round(e->point[i][j + 1].y);
		e->rise = e->y2 - e->y1;
		e->run = e->x2 - e->x1;
	}
}

void	set_down(t_env *e, int i, int j)
{
	if (i + 1 < e->height)
	{
		e->x1 = round(e->point[i][j].x);
		e->x2 = round(e->point[i + 1][j].x);
		e->y1 = round(e->point[i][j].y);
		e->y2 = round(e->point[i + 1][j].y);
		e->rise = e->y2 - e->y1;
		e->run = e->x2 - e->x1;
	}
}
