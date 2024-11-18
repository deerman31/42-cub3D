/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:47:00 by ykusano           #+#    #+#             */
/*   Updated: 2023/10/14 17:47:02 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	set_map(t_world *world, char *file_name)
{
	char	*text;
	char	*str;

	str = get_text(file_name);
	if (str == NULL)
		return (false);
	text = ft_strtrim(str, " \n");
	if (text == NULL)
	{
		free(str);
		printf("%s%s\n", ERROR, MALLOC_ER);
		return (false);
	}
	free(str);
	world->map.map = get_map(text);
	if (world->map.map == NULL)
	{
		printf("%s%s\n", ERROR, MALLOC_ER);
		return (false);
	}
	return (true);
}
