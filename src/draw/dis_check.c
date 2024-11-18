/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:43:21 by ykusano           #+#    #+#             */
/*   Updated: 2023/10/14 17:43:24 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	wall_dis(t_world *world, t_ray *ray)
{
	const double	red = ray->vec.red;
	double			s_red;

	first_cross(world, ray);
	offset(ray, red);
	cross_dis(world, ray);
	if (world->loca.vector.red - ray->vec.red < 0)
		s_red = sin(N_PI - (ray->vec.red - world->loca.vector.red));
	else
		s_red = sin(N_PI - (world->loca.vector.red - ray->vec.red));
	ray->perpe_line = ray->wall_dis * s_red;
}

void	dis_check(t_world *world)
{
	size_t	i;

	dir_dis(world);
	i = 0;
	while (i < world->num_rays)
	{
		wall_dis(world, &world->rays[i]);
		i += 1;
	}
}
