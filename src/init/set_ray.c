/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:44:59 by ykusano           #+#    #+#             */
/*   Updated: 2023/10/14 17:45:00 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	dir_set(t_ray *ray)
{
	if (ray->vec.red > W_PI && ray->vec.red < E_PI)
		ray->dir[0] = NORTH;
	else if (ray->vec.red > E_PI)
		ray->dir[0] = SOUTH;
	else
		ray->dir[0] = NONE;
	if (ray->vec.red < N_PI || ray->vec.red > S_PI)
		ray->dir[1] = WEST;
	else if (ray->vec.red > N_PI && ray->vec.red < S_PI)
		ray->dir[1] = EAST;
	else
		ray->dir[1] = NONE;
}

void	set_ray(t_world *world, t_ray *ray, double red)
{
	ray->world = world;
	ray->vec.red = red_reset(red);
	ray->h_offset.x = -1;
	ray->h_offset.y = -1;
	ray->coord.x = -1;
	ray->coord.y = -1;
	ray->h_cross_p.x = -1;
	ray->h_cross_p.y = -1;
	ray->v_cross_p.x = -1;
	ray->v_cross_p.y = -1;
	ray->wall_height = -1;
	ray->hit_point = -1;
	ray->wall_dir = NONE;
	ray->perpe_line = -1;
	ray->step = -1;
	ray->tex_pos = -1;
	ray->start = -1;
	ray->end = -1;
	ray->tex_x = -1;
	ray->tex_y = -1;
	dir_set(ray);
}
