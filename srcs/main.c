/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 18:43:20 by dcastro-          #+#    #+#             */
/*   Updated: 2017/07/17 23:52:01 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		error_msg(char *str)
{
	ft_putendl(str);
	exit(0);
}

int			my_key_funct(int keycode)
{
	ft_putstr("Key Event: ");
	ft_putendl(ft_itoa(keycode));
	if (keycode == 53)
		exit(0);
	return (0);
}

static	int	my_expose(t_env *e)
{
	static	int	i = 0;

	if (i != 0)
	{
		ft_putendl("clearing and redrawing");
		mlx_clear_window(e->mlx, e->win);
		draw_right(e);
		draw_down(e);
	}
	i = 1;
	return (0);
}

int			main(int ac, char **av)
{
	t_env	e;

	init_estruct(&e);
	if (ac != 2)
		error_msg("Arg count invalid");
	check_file(av[1], &e);
	store_points(&e, av[1]);
	setup_env(&e);
	draw_right(&e);
	draw_down(&e);
	mlx_key_hook(e.win, my_key_funct, &e);
	mlx_expose_hook(e.win, my_expose, &e);
	mlx_loop(e.mlx);
	return (0);
}
