/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:46:48 by ykusano           #+#    #+#             */
/*   Updated: 2023/10/14 17:46:50 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	strs_create(char **strs, t_map *map, size_t i)
{
	size_t	index;
	size_t	start;
	size_t	end;

	index = 0;
	while (map->map[i + index])
	{
		start_end_get(map->map[i + index], &start, &end, " ");
		if (start == 0 && end == 0)
			strs[index] = ft_strdup("");
		else
			strs[index] = ft_strndup(map->map[i + index], end);
		if (strs[index] == NULL)
		{
			printf("%s%s\n", ERROR, MALLOC_ER);
			map_free(map->map);
			map_free(strs);
			return (false);
		}
		index += 1;
	}
	strs[index] = NULL;
	return (true);
}

static bool	re_map2(t_map *map, size_t i)
{
	char	**strs;

	strs = malloc(sizeof(char *) * (map->height + 1));
	if (strs == NULL)
	{
		printf("%s%s\n", ERROR, MALLOC_ER);
		map_free(map->map);
		return (false);
	}
	if (!strs_create(strs, map, i))
		return (false);
	map_free(map->map);
	map->map = strs;
	return (true);
}

bool	re_map(t_map *map, size_t i)
{
	size_t	index;
	size_t	start;
	size_t	end;

	map->height = 0;
	while (map->map[i + map->height])
		map->height += 1;
	map->width = 0;
	index = 0;
	while (map->map[i + index])
	{
		start_end_get(map->map[i + index], &start, &end, " ");
		if (map->width < end)
			map->width = end;
		index += 1;
	}
	if (!re_map2(map, i))
		return (false);
	return (true);
}
