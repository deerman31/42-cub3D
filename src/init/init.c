/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:44:48 by ykusano           #+#    #+#             */
/*   Updated: 2023/10/14 17:44:49 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	init_ray(t_world *world)
{
	size_t	i;
	double	red;

	world->num_rays = WIN_W;
	world->fov = FOV_RED;
	red = world->loca.vector.red - world->fov / 2.00;
	world->rays = malloc(sizeof(t_ray) * world->num_rays);
	if (world->rays == NULL)
	{
		printf("%s%s\n", ERROR, MALLOC_ER);
		return (false);
	}
	i = 0;
	while (i < world->num_rays)
	{
		set_ray(world, &world->rays[i], red);
		red += world->fov / (double)world->num_rays;
		i += 1;
	}
	return (true);
}

static void	init3(t_world *world)
{
	if (!init_ray(world))
	{
		element_free(&world->map);
		map_free(world->map.map);
		texture_free(world, NONE);
		mlx_destroy_image(world->mlx.mlx, world->image);
		mlx_destroy_window(world->mlx.mlx, world->mlx.window);
		exit (EXIT_FAILURE);
	}
}

static void	init2(t_world *world)
{
	world->image = mlx_new_image(world->mlx.mlx, WIN_W, WIN_H);
	if (world->image == NULL)
	{
		element_free(&world->map);
		map_free(world->map.map);
		printf("%s%s\n", ERROR, IMG_ER);
		mlx_destroy_window(world->mlx.mlx, world->mlx.window);
		exit (EXIT_FAILURE);
	}
	world->data = (unsigned int *)mlx_get_data_addr(world->image,
			&world->bits, &world->lines, &world->endian);
	if (!texture_set(world))
	{
		element_free(&world->map);
		map_free(world->map.map);
		mlx_destroy_image(world->mlx.mlx, world->image);
		mlx_destroy_window(world->mlx.mlx, world->mlx.window);
		exit (EXIT_FAILURE);
	}
}

void	init(t_world *world)
{
	world->loca.vector.red = angle_to_radians(world->map.angle);
	world->mlx.mlx = mlx_init();
	if (world->mlx.mlx == NULL)
	{
		element_free(&world->map);
		map_free(world->map.map);
		printf("%s%s\n", ERROR, INIT_ER);
		exit (EXIT_FAILURE);
	}
	world->mlx.window = mlx_new_window(world->mlx.mlx, WIN_W, WIN_H, "CUB3D");
	if (world->mlx.window == NULL)
	{
		element_free(&world->map);
		map_free(world->map.map);
		printf("%s%s\n", ERROR, WIN_ER);
		exit (EXIT_FAILURE);
	}
	init2(world);
	init3(world);
}
