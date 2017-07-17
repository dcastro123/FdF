/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:25:10 by dcastro-          #+#    #+#             */
/*   Updated: 2017/07/17 04:40:23 by dcastro-         ###   ########.fr       */
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

# define WHITE 0xfffafa
# define BLUE 0X00242cf8
# define TURQ 0x40e0d0
# define GREEN 0x7cfc00
#define RED 0x8b0000

typedef struct s_point
{
	float z;
	float x;
	float y;
	float z2;
}				t_points;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	int		**store_arr;
	t_points **point;
	int 	x_mid;
	int 	y_mid;
	int		dist;
	int		width;
	int		height;
	float 	slope;
	float	z_max;
	float 	z_min;
	float win_wmax;
	float win_hmax;
	float threshold;
	float offset;
	float rise;
	float run;
	float delta;
	float adjust;
	float x1;
	float x2;
	float y1;
	float y2;
	float z;
	float next_z;
}				t_env;

void	error_msg(char *str);

void		init_estruct(t_env *e);
void		init_pstruct(t_points *point);

int 		check_file(char *av, t_env *e);
void		store_points(t_env *e, char *av);
t_points	**store_cpoints(t_env *e);
void		setup_env(t_env *e);
void	translate(t_env *e);

void	draw_grad_diag(t_env *e);
void	draw_sharpdiag(t_env *e);
void	draw_right(t_env *e);
void	draw_down(t_env *e);
void	set_right(t_env *e, int i, int j);
void	set_down(t_env *e, int i, int j);
void	straightdraw(t_env *e);

void	rotate(t_env *e);
void	rot_x(t_env *e);
void	rot_y(t_env *e);
void	rot_z(t_env *e);
#endif