/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:43:57 by ykusano           #+#    #+#             */
/*   Updated: 2023/10/14 17:43:58 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	h_offset(t_ray *ray, double red)
{
	if (ray->vec.red == W_PI || ray->vec.red == E_PI)
	{
		ray->h_offset.x = 0;
		ray->h_offset.y = 0;
	}
	else if (ray->vec.red < E_PI)
	{
		ray->h_offset.y = -1;
		ray->h_offset.x = -1 / tan(red);
	}
	else
	{
		ray->h_offset.y = 1;
		ray->h_offset.x = 1 / tan(red);
	}
}

static void	v_offset(t_ray *ray, double red)
{
	if (ray->vec.red == N_PI || ray->vec.red == S_PI)
	{
		ray->v_offset.x = 0;
		ray->v_offset.y = 0;
	}
	else if (ray->vec.red > N_PI && ray->vec.red < S_PI)
	{
		ray->v_offset.x = 1;
		ray->v_offset.y = tan(red);
	}
	else
	{
		ray->v_offset.x = -1;
		ray->v_offset.y = -tan(red);
	}
}

void	offset(t_ray *ray, double red)
{
	h_offset(ray, red);
	v_offset(ray, red);
}
