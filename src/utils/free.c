/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:47:23 by ykusano           #+#    #+#             */
/*   Updated: 2023/10/14 17:47:25 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	texture_free(t_world *world, size_t len)
{
	size_t	i;

	i = NORTH;
	while (i < len && world->texture[i].wall_texture != NULL)
	{
		mlx_destroy_image(world->mlx.mlx, world->texture[i].wall_texture);
		world->texture[i].wall_texture = NULL;
		i += 1;
	}
}

void	map_free(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i += 1;
	}
	free(map);
	map = NULL;
}

void	element_free(t_map *map)
{
	if (map->n_path != NULL)
		free(map->n_path);
	if (map->w_path != NULL)
		free(map->w_path);
	if (map->s_path != NULL)
		free(map->s_path);
	if (map->e_path != NULL)
		free(map->e_path);
}
