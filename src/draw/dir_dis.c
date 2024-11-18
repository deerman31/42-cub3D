/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_dis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:43:10 by ykusano           #+#    #+#             */
/*   Updated: 2023/10/14 17:43:12 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	v_dir_dis(t_world *world)
{
	double	i;

	i = 0;
	while (1)
	{
		if (i == world->loca.coord.y)
		{
			world->dir_dis.north = 0;
			world->dir_dis.south = 0;
			break ;
		}
		if ((i) < world->loca.coord.y
			&& ((i + 1)) > world->loca.coord.y)
		{
			world->dir_dis.south = ((i + 1)) - world->loca.coord.y;
			world->dir_dis.north = world->loca.coord.y - (i);
			break ;
		}
		i += 1;
	}
}

static void	h_dir_dis(t_world *world)
{
	double	i;

	i = 0;
	while (1)
	{
		if (i == world->loca.coord.x)
		{
			world->dir_dis.west = 0;
			world->dir_dis.east = 0;
			break ;
		}
		if ((i) < world->loca.coord.x
			&& ((i + 1)) > world->loca.coord.x)
		{
			world->dir_dis.west = world->loca.coord.x - (i);
			world->dir_dis.east = ((i + 1)) - world->loca.coord.x;
			break ;
		}
		i += 1;
	}
}

void	dir_dis(t_world *world)
{
	h_dir_dis(world);
	v_dir_dis(world);
}
