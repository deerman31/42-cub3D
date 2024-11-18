/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:48:26 by ykusano           #+#    #+#             */
/*   Updated: 2023/10/14 17:48:29 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	vers_strlen(const char *s, const char *end_s)
{
	size_t		len;

	if (s == NULL)
		return (0);
	if (end_s == NULL)
		return (ft_strlen(s));
	len = 0;
	while (s[len] && !ft_strchr(end_s, s[len]))
		len += 1;
	return (len);
}

bool	start_end_get(char *str, size_t *start, size_t *end, char *trim)
{
	*start = 0;
	while (str[*start] && ft_strchr(trim, str[*start]))
		*start += 1;
	*end = ft_strlen(str);
	while (0 < *end && ft_strchr(trim, str[*end]))
		*end -= 1;
	*end += 1;
	if (*start >= *end)
	{
		*start = 0;
		*end = 0;
		return (false);
	}
	return (true);
}
