/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_num_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:45:33 by ykusano           #+#    #+#             */
/*   Updated: 2023/10/14 17:45:34 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	error_message(t_world *world, int *cnt)
{
	if (!((cnt[NO] + cnt[SO] + cnt[WE] + cnt[EA] + cnt[F] + cnt[C]) == 6
			&& (cnt[NO] == 1 && cnt[SO] == 1 && cnt[WE] == 1 \
			&& cnt[EA] == 1 && cnt[F] == 1 && cnt[C] == 1)))
	{
		if ((cnt[NO] + cnt[SO] + cnt[WE] + cnt[EA] + cnt[F] + cnt[C]) > 6)
			printf("%s%s\n", ERROR, ELEMENT_OVER_ER);
		else if ((cnt[NO] + cnt[SO] + cnt[WE] + cnt[EA] + cnt[F] + cnt[C]) < 6)
			printf("%s%s\n", ERROR, ELEMENT_MISSING_ER);
		else
			printf("%s%s\n", ERROR, ELEMENT_DUP_ER);
		map_free(world->map.map);
		return (false);
	}
	return (true);
}

static bool	element_cnt(char *s, int *cnt)
{
	const char	strs[6][4] = {"NO ", "WE ", "EA ", "SO ", "F ", "C "};
	size_t		i;

	if (s[0] == '\0')
		return (true);
	i = 0;
	while (i < 6)
	{
		if (ft_strncmp(strs[i], s, ft_strlen(strs[i])) == 0
			&& ft_strlen(strs[i]) < ft_strlen(s))
		{
			cnt[i] += 1;
			return (true);
		}
		i += 1;
	}
	return (false);
}

bool	element_num_check(t_world *world, size_t *i)
{
	int		cnt[6];

	*i = 0;
	while (*i < 6)
	{
		cnt[*i] = 0;
		*i += 1;
	}
	*i = 0;
	while (world->map.map[*i])
	{
		if (!element_cnt(world->map.map[*i], cnt))
			break ;
		*i += 1;
	}
	if (!error_message(world, cnt))
		return (false);
	return (true);
}
