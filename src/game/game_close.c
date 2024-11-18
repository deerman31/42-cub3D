/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:44:14 by ykusano           #+#    #+#             */
/*   Updated: 2023/10/14 17:44:16 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_close(t_world *world)
{
	free(world->rays);
	element_free(&world->map);
	texture_free(world, NONE);
	map_free(world->map.map);
	texture_free(world, NONE);
	mlx_destroy_image(world->mlx.mlx, world->image);
	mlx_destroy_window(world->mlx.mlx, world->mlx.window);
}
