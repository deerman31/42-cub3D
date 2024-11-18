/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:44:28 by ykusano           #+#    #+#             */
/*   Updated: 2023/10/14 17:44:29 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_end(t_world *world)
{
	game_close(world);
	printf("game_end\n");
	exit (EXIT_SUCCESS);
	return (1);
}

int	game_play(t_world *world)
{
	draw(world);
	return (1);
}
