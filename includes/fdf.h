/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:25:10 by dcastro-          #+#    #+#             */
/*   Updated: 2017/07/15 17:09:37 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../libft/inc/libft.h"
#include "../minilibx_macos/mlx.h"

typedef struct s_point
{
	float x1;
	float x2;
	float y1;
	float y2;
	float z;
	float x;
	float y;
}				t_points;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	int		**store_arr;
	t_points **point;
	int 	x_mid;
	int 	y_mid;
	float 	slope;
	int		dist;
	int		width;
	int		height;
	float	z_max;
	float 	z_min;
	float win_wmax;
	float win_hmax;
}				t_env;

void		init_estruct(t_env *e);
void		init_pstruct(t_points *point);

int 		check_file(char *av, t_env *e);
void		store_points(t_env *e, char *av);
t_points	**store_cpoints(t_env *e);
void		setup_env(t_env *e);
#endif