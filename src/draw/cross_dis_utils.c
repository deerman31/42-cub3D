/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_dis_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:42:59 by ykusano           #+#    #+#             */
/*   Updated: 2023/10/14 17:43:01 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	num_set(char dir, t_ray *ray)
{
	int		n;

	if (dir == 'v')
	{
		n = -1;
		if (ray->vec.red > N_PI && ray->vec.red < S_PI)
			n = 0;
	}
	else
	{
		n = 0;
		if (ray->vec.red < E_PI)
			n = -1;
	}
	return (n);
}

char	hv_check(t_ray *ray)
{
	char	c;

	if (ray->dir[1] == WEST)
	{
		if (ray->h_cross_p.x > ray->v_cross_p.x)
			c = 'h';
		else
			c = 'v';
	}
	else
	{
		if (ray->h_cross_p.x < ray->v_cross_p.x)
			c = 'h';
		else
			c = 'v';
	}
	return (c);
}
