/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 18:43:20 by dcastro-          #+#    #+#             */
/*   Updated: 2017/07/15 19:11:04 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// int	my_key_funct(int keycode, void *mlx)
// {
// 	printf("key event %d\n", keycode);
// 	if (keycode == 53)
// 		exit(0);
// 	return (0);
// }

// t_point	init_pstruct(t_point *coord)
// {
// 	point->x1 = 0;
// 	point->y1 = 0;
// 	point->x2 = 0;
// 	point->y2 = 0;
	// point->x = 0;
	// point->y = 0;
	// point->z = 0;
// }

int	main(int ac, char **av)
{
	t_env e;

	init_estruct(&e);
	if (ac > 2)
	{
		ft_putendl("Usage: ./fdf (filename)");
		exit(0);
	}
	if ((check_file(av[1], &e)) == 1)
		store_points(&e, av[1]);
	else
		ft_putendl("Invalid File");
	setup_env(&e);
	// start_draw(&e, &coords);
//	mlx_key_hook(e.win, my_key_funct, 0);
//	mlx_loop(e.mlx);
	return (0);
}
