/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_dis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:42:36 by ykusano           #+#    #+#             */
/*   Updated: 2023/10/14 17:42:40 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	wall_cross_check(t_ray *ray, t_world *world, t_coord *hvxy, char hv)
{
	const int	hn = num_set(hv, ray);
	const int	vn = num_set(hv, ray);

	if (hv == 'h' && \
		world->map.map[(int)(hvxy[H].y + hn)][(int)hvxy[H].x] == '1')
	{
		ray->hit_point = hvxy[H].x * GRID;
		ray->wall_dis = wall_dis_cal(ray->world->loca.coord.x,
				ray->world->loca.coord.y, hvxy[H].x, hvxy[H].y) * GRID;
		ray->wall_dir = ray->dir[0];
		return (true);
	}
	else if (hv == 'v' && \
		world->map.map[(int)hvxy[V].y][(int)(hvxy[V].x + vn)] == '1')
	{
		ray->hit_point = hvxy[V].y * GRID;
		ray->wall_dis = wall_dis_cal(ray->world->loca.coord.x,
				ray->world->loca.coord.y, hvxy[V].x, hvxy[V].y) * GRID;
		ray->wall_dir = ray->dir[1];
		return (true);
	}
	return (false);
}

static void	h_reset(char *hv, t_ray *ray, t_coord *hvxy)
{
	hvxy[H].x += ray->h_offset.x;
	hvxy[H].y += ray->h_offset.y;
	if (ray->dir[1] == WEST)
	{
		if (hvxy[H].x < hvxy[V].x)
			*hv = 'v';
	}
	else
	{
		if (hvxy[H].x > hvxy[V].x)
			*hv = 'v';
	}
}

static void	v_reset(char *hv, t_ray *ray, t_coord *hvxy)
{
	hvxy[V].x += ray->v_offset.x;
	hvxy[V].y += ray->v_offset.y;
	if (ray->dir[1] == WEST)
	{
		if (hvxy[H].x > hvxy[V].x)
			*hv = 'h';
	}
	else
	{
		if (hvxy[H].x < hvxy[V].x)
			*hv = 'h';
	}
}

void	cross_dis(t_world *world, t_ray *ray)
{
	t_coord		hvxy[2];
	char		hv;

	hvxy[H].x = ray->h_cross_p.x;
	hvxy[H].y = ray->h_cross_p.y;
	hvxy[V].x = ray->v_cross_p.x;
	hvxy[V].y = ray->v_cross_p.y;
	hv = hv_check(ray);
	while (1)
	{
		if (wall_cross_check(ray, world, hvxy, hv))
			return ;
		if (hv == 'h')
			h_reset(&hv, ray, hvxy);
		else
			v_reset(&hv, ray, hvxy);
	}
}
