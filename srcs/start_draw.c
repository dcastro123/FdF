/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 19:11:36 by dcastro-          #+#    #+#             */
/*   Updated: 2017/07/17 04:33:04 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
 #include "../includes/fdf.h"

void	draw_grad_diag(t_env *e)
{
	float i;
	float temp;

	i = e->y1;
	e->delta = fabsf(e->slope);
	if (e->x2 < e->x1)
	{
		temp = e->x1;
		e->x1 = e->x2;
		e->x2 = temp;
		i = e->y2;
	}
	while (e->x1 < (e->x2))
	{
		mlx_pixel_put(e->mlx, e->win, e->x1, i, TURQ);
		e->offset += e->delta;
		if (e->offset >= e->threshold)
		{
			i += e->adjust;
			e->threshold += 1.0;
		}
		e->x1++;
	}
}

void	draw_sharpdiag(t_env *e)
{
	float i;
	float temp;

	i = e->x1;
	e->delta = fabsf(e->run / e->rise);
	if (e->y2 < e->y1)
	{
		temp = e->y1;
		e->y1 = e->y2;
		e->y2 = temp;
		i = e->x2;
	}
	while (e->y1 < e->y2)
	{
		mlx_pixel_put(e->mlx, e->win, i, e->y1, RED);
		e->offset += e->delta;
		if (e->offset >= e->threshold)
		{
			i += e->adjust;
			e->threshold += 1;
		}
		e->y1++;
	}
}

void	straightdraw(t_env *e)
{
	float temp;

	temp = 0;
	if (e->y2 < e->y1)
	{
		temp = e->y1;
		e->y1 = e->y2;
		e->y2 = temp;
	}
	while (e->y1 < e->y2)
	{
		mlx_pixel_put(e->mlx, e->win, e->x1, e->y1, GREEN);
		e->y1++;
	}
}

void	draw_right(t_env *e)
{
	int i;
	int j;

	i = -1;
	while (++i < e->height)
	{
		j = -1;
		while (++j + 1 < e->width)
		{
			set_right(e, i, j);
			if (e->run == 0 && (j + 1 < e->height))
				straightdraw(e);
			else
			{
				e->slope = e->rise / e->run;
				e->offset = 0;
				e->adjust = e->slope >= 0 ? 1: -1;
				e->threshold = 0.5;
				if (e->slope <= 1 && e->slope >= -1)
					draw_grad_diag(e);
				else
					draw_sharpdiag(e);
			}
		}
	}
}

void	draw_down(t_env *e)
{
	int i;
	int j;

	i = -1;
	while (++i + 1 < e->height)
	{
		j = -1;
		while (++j < e->width)
		{
			set_down(e, i, j);
			if (e->run == 0 && (i + 1 < e->height))
				straightdraw(e);
			else
			{
				e->slope = e->rise / e->run;
				e->offset = 0;
				e->adjust = e->slope >= 0 ? 1: -1;
				e->threshold = 0.5;
				if (e->slope <= 1 && e->slope >= -1)
					draw_grad_diag(e);
				else
					draw_sharpdiag(e);
			}
		}
	}
}
