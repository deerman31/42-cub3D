/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_cross.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:43:47 by ykusano           #+#    #+#             */
/*   Updated: 2023/10/14 17:43:48 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	h_north(t_world *world, t_ray *ray, double t_red)
{
	const double	py = world->loca.coord.y;
	const double	px = world->loca.coord.x;

	ray->h_cross_p.x = px - world->dir_dis.north / t_red;
	ray->h_cross_p.y = (py / 1) * 1 - world->dir_dis.north;
}

static void	h_south(t_world *world, t_ray *ray, double t_red)
{
	const double	py = world->loca.coord.y;
	const double	px = world->loca.coord.x;

	ray->h_cross_p.x = px + world->dir_dis.south / t_red;
	ray->h_cross_p.y = (py / 1) * 1 + world->dir_dis.south;
}

static void	v_east(t_world *world, t_ray *ray, double t_red)
{
	const double	py = world->loca.coord.y;
	const double	px = world->loca.coord.x;

	ray->v_cross_p.x = ((px / 1) * 1) + world->dir_dis.east;
	ray->v_cross_p.y = py + world->dir_dis.east * t_red;
}

static void	v_west(t_world *world, t_ray *ray, double t_red)
{
	const double	py = world->loca.coord.y;
	const double	px = world->loca.coord.x;

	ray->v_cross_p.x = ((px / 1) * 1) - world->dir_dis.west;
	ray->v_cross_p.y = py - world->dir_dis.west * t_red;
}

void	first_cross(t_world *world, t_ray *ray)
{
	const double	t_red = tan(ray->vec.red);

	if (ray->vec.red == W_PI || ray->vec.red == E_PI)
	{
		ray->h_cross_p.x = -1;
		ray->h_cross_p.y = -1;
	}
	else if (ray->vec.red < E_PI)
		h_north(world, ray, t_red);
	else if (ray->vec.red < MAX_PI)
		h_south(world, ray, t_red);
	if (ray->vec.red == N_PI || ray->vec.red == S_PI)
	{
		ray->v_cross_p.x = -1;
		ray->v_cross_p.y = -1;
	}
	else if (ray->vec.red > N_PI && ray->vec.red < S_PI)
		v_east(world, ray, t_red);
	else
		v_west(world, ray, t_red);
}
