/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 18:43:20 by dcastro-          #+#    #+#             */
/*   Updated: 2017/07/12 22:02:42 by dcastro-         ###   ########.fr       */
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
// }

// t_env	init_estruct(t_env *e)
// {





// }

int	main(int ac, char **av)
{
	//t_env e;

	// e.mlx = mlx_init();
	// e.win = mlx_new_window(e.mlx, 600, 600, "mlx 42");
	// init_pstruct(&coord);
	// init_estruct(&e);
	if (ac > 2)
	{
		ft_putendl("too many arguments");
		exit(0);
	}
	if ((check_file(av[1])) == 1)
		ft_putendl("Success!");
	else
		ft_putendl("Invalid File");
//	mlx_key_hook(e.win, my_key_funct, 0);
//	mlx_loop(e.mlx);
	return (0);
}
