/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:46:07 by ykusano           #+#    #+#             */
/*   Updated: 2023/10/14 17:46:10 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	map_len(char *s)
{
	size_t		size;
	size_t		i;

	size = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			size += 1;
		i += 1;
	}
	return (size);
}

static char	*line(char *s)
{
	size_t	len;
	char	*str;

	len = 0;
	while (s[len] && s[len] != '\n')
		len += 1;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s, len + 1);
	return (str);
}

char	**get_map(char *text)
{
	char			**map;
	size_t			i;
	size_t			j;
	const size_t	size = map_len(text);

	map = malloc(sizeof(char *) * (size + 1));
	if (map == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (j < size)
	{
		map[j] = line(&text[i]);
		if (map[j] == NULL)
		{
			free(text);
			map_free(map);
			return (NULL);
		}
		i += ft_strlen(map[j]) + 1;
		j += 1;
	}
	map[j] = NULL;
	free(text);
	return (map);
}
