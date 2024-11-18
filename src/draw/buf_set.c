/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:42:05 by ykusano           #+#    #+#             */
/*   Updated: 2023/10/14 17:42:08 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	texture_x_set(t_ray *ray, double tex_pos_ratio)
{
	int		tex_x;

	tex_x = (int)(tex_pos_ratio * ray->world->texture[ray->wall_dir].width);
	if (tex_x < 0)
		tex_x = 0;
	else if (tex_x >= ray->world->texture[ray->wall_dir].width)
		tex_x = ray->world->texture[ray->wall_dir].width - 1;
	return (tex_x);
}

static void	buf_info_set(t_ray *ray)
{
	ray->wall_height = (WIN_H * GRID / ray->perpe_line);
	if (ray->wall_dir == NORTH || ray->wall_dir == EAST)
		ray->tex_x = texture_x_set(ray, fmod(ray->hit_point, GRID) / GRID);
	else if (ray->wall_dir == WEST || ray->wall_dir == SOUTH)
		ray->tex_x = texture_x_set(ray, \
			(GRID - fmod(ray->hit_point, GRID)) / GRID);
	ray->start = (WIN_H / 2) - (ray->wall_height / 2);
	if (ray->start < 0)
		ray->start = 0;
	ray->end = (WIN_H / 2) + (ray->wall_height / 2);
	if (ray->end >= WIN_H)
		ray->end = WIN_H - 1;
	ray->step = 1.0 * ray->world->texture[ray->wall_dir].height \
	/ ray->wall_height;
	ray->tex_pos = (ray->start - WIN_H / 2 + ray->wall_height / 2) * ray->step;
}

static void	color_set(t_ray *ray, int x, int y)
{
	ray->tex_y = fmod(ray->tex_pos, \
	ray->world->texture[ray->wall_dir].height - 1);
	if (ray->tex_y < 0)
		ray->tex_y = 0;
	else if (ray->tex_y >= ray->world->texture[ray->wall_dir].height)
		ray->tex_y = ray->world->texture[ray->wall_dir].height - 1;
	ray->world->data[y * WIN_W + x] = \
	ray->world->texture[ray->wall_dir].data[ray->tex_y \
	* ray->world->texture[ray->wall_dir].width + ray->tex_x];
	ray->tex_pos += ray->step;
}

void	buf_set(t_ray *ray, size_t x)
{
	int		y;

	buf_info_set(ray);
	y = 0;
	while (y < ray->start && y < WIN_H)
	{
		ray->world->data[y * WIN_W + x] = ray->world->map.c_color;
		y += 1;
	}
	while (y < ray->end && y < WIN_H)
	{
		color_set(ray, x, y);
		y += 1;
	}
	while (y < WIN_H)
	{
		ray->world->data[y * WIN_W + x] = ray->world->map.f_color;
		y += 1;
	}
}
