/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:44:36 by ykusano           #+#    #+#             */
/*   Updated: 2023/10/14 18:26:56 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	re_ray(t_world *world)
{
	double			red;
	size_t			i;

	red = world->loca.vector.red - world->fov / 2.00;
	i = 0;
	while (i < world->num_rays)
	{
		set_ray(world, &world->rays[i], red);
		red += world->fov / (double)world->num_rays;
		i += 1;
	}
}

static void	wall_check(t_world *world, double x, double y)
{
	const double	west = world->loca.coord.x - world->dir_dis.west - 1;
	const double	east = world->loca.coord.x + world->dir_dis.east;
	const double	south = world->loca.coord.y + world->dir_dis.south;
	const double	north = world->loca.coord.y - world->dir_dis.north - 1;
	const char		**map = (const char **)world->map.map;

	if (y < 0 && world->dir_dis.north <= -y && \
		map[(int)(north)][(int)world->loca.coord.x] == '1')
		y = -world->dir_dis.north + 0.1;
	else if (y > 0 && world->dir_dis.south <= y && \
			map[(int)(south)][(int)world->loca.coord.x] == '1')
		y = world->dir_dis.south - 0.1;
	if (x < 0 && world->dir_dis.west <= -x && \
			map[(int)world->loca.coord.y][(int)west] == '1')
		x = -world->dir_dis.west + 0.1;
	else if (x > 0 && world->dir_dis.east <= x && \
			map[(int)world->loca.coord.y][(int)east] == '1')
		x = world->dir_dis.east - 0.1;
	if (map[(int)(world->loca.coord.y + y)] \
		[(int)(world->loca.coord.x + x)] != '1')
	{
		world->loca.coord.x += x;
		world->loca.coord.y += y;
	}
}

static void	xy_move(t_world *world, int keycode)
{
	double	red;
	double	x;
	double	y;
	double	minus_angle;

	minus_angle = W_PI;
	if (keycode == KEY_A)
		minus_angle = N_PI;
	else if (keycode == KEY_S)
		minus_angle = E_PI;
	else if (keycode == KEY_D)
		minus_angle = S_PI;
	red = world->loca.vector.red - minus_angle;
	x = 0.5 * -cos(red);
	y = 0.5 * -sin(red);
	wall_check(world, x, y);
}

int	key_op(int keycode, t_world *world)
{
	if (keycode == KEY_ESC)
		game_end(world);
	else if (keycode == KEY_A || keycode == KEY_D || \
	keycode == KEY_S || keycode == KEY_W)
		xy_move(world, keycode);
	else if (keycode == KEY_LEFT)
		world->loca.vector.red = red_reset(world->loca.vector.red - 0.087266);
	else if (keycode == KEY_RIGHT)
		world->loca.vector.red = red_reset(world->loca.vector.red + 0.087266);
	else
		return (1);
	re_ray(world);
	dis_check(world);
	draw(world);
	return (1);
}
