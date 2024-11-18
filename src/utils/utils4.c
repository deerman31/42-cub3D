/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:48:17 by ykusano           #+#    #+#             */
/*   Updated: 2023/10/14 17:48:18 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	pc;

	ptr = (unsigned char *)b;
	pc = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		ptr[i] = pc;
		i++;
	}
	return (b);
}

static size_t	lead_check(char const *s1, char const *set)
{
	size_t	lead;

	lead = 0;
	while (s1[lead])
	{
		if (ft_strchr(set, s1[lead]))
			lead++;
		else
			break ;
	}
	return (lead);
}

static size_t	end_check(char const *s1, char const *set)
{
	size_t	end;

	end = ft_strlen(s1);
	while (end > 0)
	{
		if (ft_strchr(set, s1[end - 1]))
			end--;
		else
			break ;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	lead;
	size_t	end;
	size_t	len;
	char	*ptr;

	if (s1 == NULL || set == NULL)
		return (NULL);
	lead = lead_check(s1, set);
	end = end_check(s1, set);
	if (lead >= end)
		return (ft_strdup(""));
	len = end - lead;
	ptr = ft_substr(s1, lead, len);
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start || len == 0)
		return (ft_strdup(""));
	if (s_len - start < len)
		len = s_len - start;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
