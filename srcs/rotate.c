/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 00:39:30 by dcastro-          #+#    #+#             */
/*   Updated: 2017/07/17 03:35:08 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rot_z(t_env *e)
{
	int i;
	int j;
	float x;
	float y;

	i  = -1;
	while (++i < e->height)
	{
		j = -1;
		while (++j < e->width)
		{
			x = e->point[i][j].x;
			y = e->point[i][j].y;
			e->point[i][j].x = (x * cos(0.7854)) - (y * sin(0.7854));
			e->point[i][j].y = (x * sin(0.7854)) + (y * cos(0.7854));
		}
	}
}

void	rot_y(t_env *e)
{
	int i;
	int j;
	float x;
	float z;

	i = -1;
	while (++i < e->height)
	{
		j = -1;
		while (++j < e->width)
		{
			x = e->point[i][j].x;
			z = e->point[i][j].z;
			e->point[i][j].x = (x * cos(0.0524)) + (z * sin(0.0524));
			e->point[i][j].z = -(x * sin(0.0524)) + (z * cos(0.0524));
		}
	}
}

void	rot_x(t_env *e)
{
	int i;
	int j;
	float z;
	float y;

	i = -1;
	while (++i < e->height)
	{
		j = -1;
		while (++j < e->width)
		{
			y = e->point[i][j].y;
			z = e->point[i][j].z;
			e->point[i][j].y = (y * cos(0.6982)) - (z * sin(0.6982));
			e->point[i][j].z = (y * sin(0.6982)) + (z * sin(0.6982));
		}
	}
}

void	rotate(t_env *e)
{
	rot_z(e);
	rot_x(e);
	rot_y(e);
}