/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:43:37 by ykusano           #+#    #+#             */
/*   Updated: 2023/10/14 17:43:38 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw(t_world *world)
{
	size_t	i;

	i = 0;
	while (i < world->num_rays)
	{
		buf_set(&world->rays[i], i);
		i += 1;
	}
	mlx_put_image_to_window(world->mlx.mlx, \
	world->mlx.window, world->image, 0, 0);
}
