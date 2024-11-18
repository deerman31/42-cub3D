/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:45:45 by ykusano           #+#    #+#             */
/*   Updated: 2023/10/14 17:45:47 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fc_color_set(t_map *map_info, char *str, size_t *cnt)
{
	size_t			start;
	size_t			end;
	unsigned int	color[3];

	if (!ft_strncmp(str, "F ", 2))
		start_end_get(&str[2], &start, &end, "F 	");
	else
		start_end_get(&str[2], &start, &end, "C 	");
	start += 2;
	color[0] = ft_atoi(&str[start]);
	while (str[start] != ',')
		start += 1;
	start += 1;
	color[1] = ft_atoi(&str[start]);
	while (str[start] != ',')
		start += 1;
	start += 1;
	color[2] = ft_atoi(&str[start]);
	if (!ft_strncmp(str, "F ", 2))
		map_info->f_color = (color[0] << 16) | (color[1] << 8) | color[2];
	else
		map_info->c_color = (color[0] << 16) | (color[1] << 8) | color[2];
	*cnt += 1;
}

static bool	tex_set(t_map *map_info, char *str, size_t start, size_t end)
{
	if (!ft_strncmp(str, "NO ", 3))
	{
		map_info->n_path = ft_strndup(&str[start], end + 3 - start);
		if (map_info->n_path == NULL)
			return (false);
	}
	if (!ft_strncmp(str, "SO ", 3))
	{
		map_info->s_path = ft_strndup(&str[start], end + 3 - start);
		if (map_info->s_path == NULL)
			return (false);
	}
	if (!ft_strncmp(str, "WE ", 3))
	{
		map_info->w_path = ft_strndup(&str[start], end + 3 - start);
		if (map_info->w_path == NULL)
			return (false);
	}
	if (!ft_strncmp(str, "EA ", 3))
	{
		map_info->e_path = ft_strndup(&str[start], end + 3 - start);
		if (map_info->e_path == NULL)
			return (false);
	}
	return (true);
}

static int	path_is(char *s)
{
	if (!ft_strncmp(s, "NO ", 3) || !ft_strncmp(s, "SO ", 3)
		|| !ft_strncmp(s, "WE ", 3) || !ft_strncmp(s, "EA ", 3))
		return (1);
	if (!ft_strncmp(s, "F ", 2) || !ft_strncmp(s, "C ", 2))
		return (2);
	return (0);
}

static void	path_init(t_map *map_info)
{
	map_info->n_path = NULL;
	map_info->s_path = NULL;
	map_info->w_path = NULL;
	map_info->e_path = NULL;
}

bool	element_set(t_map *map_info)
{
	size_t		n[4];

	path_init(map_info);
	n[0] = 0;
	n[1] = 0;
	while (n[1] != 6)
	{
		if (path_is(map_info->map[n[0]]) == 1)
		{
			start_end_get(&map_info->map[n[0]][3], &n[2], &n[3], " 	");
			if (!tex_set(map_info, map_info->map[n[0]], n[2] + 3, n[3]))
			{
				element_free(map_info);
				return (false);
			}
			n[1] += 1;
		}
		if (path_is(map_info->map[n[0]]) == 2)
			fc_color_set(map_info, map_info->map[n[0]], &n[1]);
		n[0] += 1;
	}
	return (true);
}
