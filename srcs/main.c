/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 18:43:20 by dcastro-          #+#    #+#             */
/*   Updated: 2017/07/03 17:58:41 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_macos/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct	s_st
{
	void	*mlx;
	void	*win;
	int		a;
	int		b;
}				t_st;


int	my_key_funct(int keycode, void *mlx, t_st *e)
{
	printf("key event %d\n", keycode);
	if (keycode == 53)
		exit(0);
//	mlx_pixel_put(mlx, win, 1, 1, 0xFF00FF);
	return (0);
}

int	my_mouse_funct(int button, int x, int y, t_st *e)
{
	printf("button event %d at [%d][%d]\n", button, x, y);
	int i=x, j=y;
	while(x++ < (i + 10))
	{
		y=j;
		while(y++< j+10)
			mlx_pixel_put(e->mlx, e->win, x, y, 0x87ceff);
	}
	return (0);
}

int	main()
{
	t_st e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 600, 600, "mlx 42");
//	init_struct(&e);
	mlx_mouse_hook(e.win, my_mouse_funct, &e);
	mlx_key_hook(e.win, my_key_funct, &e);
	mlx_loop(e.mlx);
	return (0);
}
