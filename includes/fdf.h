/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:25:10 by dcastro-          #+#    #+#             */
/*   Updated: 2017/07/13 22:00:08 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <sys/types.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../libft/inc/libft.h"
#include "../minilibx_macos/mlx.h"

typedef struct	s_env
{
	void	*mlx;
	void	*win;
//	t_point point;
	int		**store_arr;
	int 	mid;
	int 	slope;
	int		dist;
	int		width;
	int		height;
	int		z_max;
	int 	z_min;
}				t_env;

typedef struct s_points
{
	int	x1;
	int x2;
	int y1;
	int y2;
	int z;
	int x;
	int y;
}				t_point;

void	init_estruct(t_env *e);

int check_file(char *av, t_env *e);
void	store_points(t_env *e, char *av);
#endif