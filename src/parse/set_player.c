/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:47:09 by ykusano           #+#    #+#             */
/*   Updated: 2023/10/14 17:47:11 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_player2(t_world *world, size_t x, size_t y)
{
	char	**map;

	map = world->map.map;
	world->loca.coord.y = y + 0.5;
	world->loca.coord.x = x + 0.5;
	world->map.player_x = x;
	world->map.player_y = y;
	if (map[y][x] == 'N')
		world->map.angle = 90;
	else if (map[y][x] == 'W')
		world->map.angle = 0;
	else if (map[y][x] == 'E')
		world->map.angle = 180;
	else if (map[y][x] == 'S')
		world->map.angle = 270;
}

void	set_player(t_world *world)
{
	char	**map;
	size_t	x;
	size_t	y;

	map = world->map.map;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_strrchr("NESW", map[y][x]))
			{
				set_player2(world, x, y);
				return ;
			}
			x += 1;
		}
		y += 1;
	}
}
