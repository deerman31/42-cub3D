/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:45:07 by ykusano           #+#    #+#             */
/*   Updated: 2023/10/14 17:45:11 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	north_set(t_world *world)
{
	world->texture[NORTH].wall_texture = mlx_xpm_file_to_image(world->mlx.mlx,
			world->map.n_path, &world->texture[NORTH].width,
			&world->texture[NORTH].height);
	if (world->texture[NORTH].wall_texture == NULL)
	{
		printf("%s%s\n", ERROR, XPM_ER);
		return (false);
	}
	world->texture[NORTH].data = (unsigned int *)mlx_get_data_addr \
	(world->texture[NORTH].wall_texture,
			&world->texture[NORTH].bits, &world->texture[NORTH].lines,
			&world->texture[NORTH].endian);
	world->texture[NORTH].direction = NORTH;
	return (true);
}

static bool	south_set(t_world *world)
{
	world->texture[SOUTH].wall_texture = \
	mlx_xpm_file_to_image(world->mlx.mlx, world->map.s_path,
			&world->texture[SOUTH].width, &world->texture[SOUTH].height);
	if (world->texture[SOUTH].wall_texture == NULL)
	{
		printf("%s%s\n", ERROR, XPM_ER);
		texture_free(world, SOUTH);
		return (false);
	}
	world->texture[SOUTH].data = \
	(unsigned int *)mlx_get_data_addr(world->texture[SOUTH].wall_texture,
			&world->texture[SOUTH].bits, &world->texture[SOUTH].lines,
			&world->texture[SOUTH].endian);
	world->texture[SOUTH].direction = SOUTH;
	return (true);
}

static bool	west_set(t_world *world)
{
	world->texture[WEST].wall_texture = \
	mlx_xpm_file_to_image(world->mlx.mlx, world->map.w_path,
			&world->texture[WEST].width, &world->texture[WEST].height);
	if (world->texture[WEST].wall_texture == NULL)
	{
		printf("%s%s\n", ERROR, XPM_ER);
		texture_free(world, WEST);
		return (false);
	}
	world->texture[WEST].data = \
	(unsigned int *)mlx_get_data_addr(world->texture[WEST].wall_texture,
			&world->texture[WEST].bits, &world->texture[WEST].lines,
			&world->texture[WEST].endian);
	world->texture[WEST].direction = WEST;
	return (true);
}

static bool	east_set(t_world *world)
{
	world->texture[EAST].wall_texture = \
	mlx_xpm_file_to_image(world->mlx.mlx, world->map.e_path,
			&world->texture[EAST].width, &world->texture[EAST].height);
	if (world->texture[EAST].wall_texture == NULL)
	{
		printf("%s%s\n", ERROR, XPM_ER);
		texture_free(world, EAST);
		return (false);
	}
	world->texture[EAST].data = \
	(unsigned int *)mlx_get_data_addr(world->texture[EAST].wall_texture,
			&world->texture[EAST].bits, &world->texture[EAST].lines,
			&world->texture[EAST].endian);
	world->texture[EAST].direction = EAST;
	return (true);
}

bool	texture_set(t_world *world)
{
	if (!north_set(world))
		return (false);
	if (!east_set(world))
		return (false);
	if (!south_set(world))
		return (false);
	if (!west_set(world))
		return (false);
	return (true);
}
