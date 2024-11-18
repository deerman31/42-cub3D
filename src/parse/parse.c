/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:46:39 by ykusano           #+#    #+#             */
/*   Updated: 2023/10/14 19:26:26 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	wall_close_check2(char **map, size_t i, size_t j, size_t height)
{
	if (i == 0 || i == height - 1 || j == 0 || j == ft_strlen(map[i]) - 1)
	{
		if (map[i][j] == '0')
			return (false);
	}
	else if (map[i][j] == '0')
	{
		if ((ft_strlen(map[i - 1]) - 1 < j) || ft_strchr(" ", map[i - 1][j]))
			return (false);
		if ((ft_strlen(map[i + 1]) - 1 < j) || ft_strchr(" ", map[i + 1][j]))
			return (false);
		if (map[i][j - 1] == ' ')
			return (false);
		if (map[i][j + 1] == ' ')
			return (false);
	}
	return (true);
}

bool	wall_close_check(t_map *map_info)
{
	size_t		i;
	size_t		j;
	const char	**map = (const char **)map_info->map;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!wall_close_check2(map_info->map, i, j, map_info->height))
				return (false);
			j += 1;
		}
		i += 1;
	}
	return (true);
}

static bool	player_wall_check(t_world *world)
{
	const size_t	x = world->loca.coord.x;
	const size_t	y = world->loca.coord.y;
	bool			flag;

	flag = true;
	if (x == 0 || y == 0 || x == world->map.width - 1
		|| y == world->map.height -1)
		flag = false;
	else if (world->map.map[y + 1][x] == ' ')
		flag = false;
	else if (world->map.map[y - 1][x] == ' ')
		flag = false;
	else if (world->map.map[y][x + 1] == ' ')
		flag = false;
	else if (world->map.map[y][x - 1] == ' ')
		flag = false;
	if (flag == false)
	{
		element_free(&world->map);
		map_free(world->map.map);
		printf("%s%s\n", ERROR, PLAYER_WALL_OFF);
		return (false);
	}
	return (flag);
}

static bool	parse2(t_world *world)
{
	if (!map_mark_check(&world->map))
		return (false);
	set_player(world);
	if (!player_wall_check(world))
		return (false);
	if (world->map.width > 1000 || world->map.height > 1000)
	{
		element_free(&world->map);
		map_free(world->map.map);
		printf("%s%s\n", ERROR, MAP_BIG);
		return (false);
	}
	if (!wall_close_check(&world->map))
	{
		element_free(&world->map);
		map_free(world->map.map);
		printf("%s%s\n", ERROR, MAP_WALL_OFF);
		return (false);
	}
	return (true);
}

bool	parse(t_world *world)
{
	size_t		i;

	if (!element_num_check(world, &i))
		return (false);
	if (!element_value_check(world->map.map))
		return (false);
	if (!element_set(&world->map))
	{
		map_free(world->map.map);
		printf("%s%s\n", ERROR, MALLOC_ER);
		return (false);
	}
	if (!re_map(&world->map, i))
	{
		element_free(&world->map);
		return (false);
	}
	if (!parse2(world))
		return (false);
	return (true);
}
