/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_mark_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:46:30 by ykusano           #+#    #+#             */
/*   Updated: 2023/10/14 17:46:31 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	map_mark_check2(char *str, int *flag)
{
	size_t		i;

	i = 0;
	while (str[i])
	{
		if (!ft_strrchr("10NWES ", str[i]))
		{
			*flag = -1;
			printf("%s%s\n", ERROR, MAP_INAP);
			break ;
		}
		if (ft_strrchr("NWES", str[i]))
		{
			if (*flag == 1)
			{
				*flag = -1;
				printf("%s%s\n", ERROR, MAP_DUP);
				break ;
			}
			*flag = 1;
		}
		i += 1;
	}
}

bool	map_mark_check(t_map *map_info)
{
	size_t		i;
	int			flag;
	const char	**map = (const char **)map_info->map;

	i = 0;
	flag = 0;
	while (map[i] && flag >= 0)
	{
		map_mark_check2((char *)map[i], &flag);
		i += 1;
	}
	if (flag == 0)
		printf("%s%s\n", ERROR, MAP_P_NO);
	if (flag < 1)
	{
		element_free(map_info);
		map_free(map_info->map);
		return (false);
	}
	return (true);
}
