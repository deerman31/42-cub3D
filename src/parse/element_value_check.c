/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_value_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:45:58 by ykusano           #+#    #+#             */
/*   Updated: 2023/10/14 19:14:54 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	rgb_check2(char *s, size_t i, size_t end)
{
	size_t	cnt;

	cnt = 0;
	while (i < end)
	{
		if (!ft_strchr("0123456789", s[i]))
		{
			printf("%s%s\n", ERROR, COLOR_COMMAS2);
			return (false);
		}
		if (ft_atoi(&s[i]) > 255 || ft_atoi(&s[i]) < 0)
		{
			printf("%s%s\n", ERROR, COLOR_OVER);
			return (false);
		}
		cnt += 1;
		i += vers_strlen(&s[i], ", 	") + 1;
	}
	if (cnt != 3)
	{
		printf("%s%s\n", ERROR, COLOR_REQ);
		return (false);
	}
	return (true);
}

static bool	rgb_value_check(char *s, size_t i, size_t end)
{
	size_t	cnt;

	cnt = 0;
	while (i < end)
	{
		if (!ft_strchr("0123456789,", s[i]))
		{
			printf("%s%s\n", ERROR, COLOR_INAPPROPRIATE);
			return (false);
		}
		if (s[i] == ',')
			cnt += 1;
		i += 1;
	}
	if (cnt != 2)
	{
		printf("%s%s\n", ERROR, COLOR_COMMAS);
		return (false);
	}
	return (true);
}

static bool	rgb_check(char *s)
{
	size_t	start;
	size_t	end;

	if (!start_end_get(s, &start, &end, " 	"))
	{
		printf("%s%s\n", ERROR, COLOR_MISSING);
		return (false);
	}
	if (!rgb_value_check(s, start, end))
		return (false);
	if (!rgb_check2(s, start, end))
		return (false);
	return (true);
}

static bool	element_value_check2(char *str, int *c, char **map)
{
	size_t	start;
	size_t	end;

	if ((!ft_strncmp(str, "F ", 2) || !ft_strncmp(str, "C ", 2)))
	{
		if (!rgb_check(&str[2]))
		{
			map_free(map);
			return (false);
		}
		*c += 1;
	}
	else if (!ft_strncmp(str, "NO ", 3) || !ft_strncmp(str, "SO ", 3)
		|| !ft_strncmp(str, "WE ", 3) || !ft_strncmp(str, "EA ", 3))
	{
		if (!start_end_get(&str[3], &start, &end, " 	"))
		{
			printf("%s%s\n", ERROR, TEXTURE_MISSING);
			map_free(map);
			return (false);
		}
		*c += 1;
	}
	return (true);
}

bool	element_value_check(char **map)
{
	size_t	i;
	int		c;

	i = 0;
	c = 0;
	while (c != 6 && map[i])
	{
		if (!element_value_check2(map[i], &c, map))
			return (false);
		i += 1;
	}
	return (true);
}
