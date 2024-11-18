/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:41:46 by ykusano           #+#    #+#             */
/*   Updated: 2023/10/14 18:42:51 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_world	world;

	if (!arg_check(argc, argv))
		return (1);
	if (!set_map(&world, argv[1]))
		return (1);
	if (!parse(&world))
		return (1);
	init(&world);
	dis_check(&world);
	mlx_hook(world.mlx.window, 2, 1L << 0, key_op, &world);
	mlx_hook(world.mlx.window, 17, 1L << 0, game_end, &world);
	mlx_loop_hook(world.mlx.mlx, game_play, &world);
	mlx_loop(world.mlx.mlx);
	game_close(&world);
	return (0);
}
/*
void	end(void)__attribute__((destructor));

void	end(void)
{
	system("leaks cub3D");
}
*/
