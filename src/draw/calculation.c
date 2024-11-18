/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:42:19 by ykusano           #+#    #+#             */
/*   Updated: 2023/10/14 17:42:21 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	angle_to_radians(double angle)
{
	double	n;

	n = angle * (M_PI / 180);
	return (n);
}

double	red_reset(double red)
{
	if (red >= W_PI && red < MAX_PI)
		return (red);
	if (red < W_PI)
	{
		while (red < W_PI)
			red += MAX_PI;
	}
	else if (red >= MAX_PI)
	{
		while (red >= MAX_PI)
			red -= MAX_PI;
	}
	return (red);
}

double	wall_dis_cal(double x1, double y1, double x2, double y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}
