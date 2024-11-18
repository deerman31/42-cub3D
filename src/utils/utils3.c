/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:47:48 by ykusano           #+#    #+#             */
/*   Updated: 2023/10/14 17:47:49 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*pd;
	const unsigned char	*ps;

	pd = (unsigned char *)dst;
	ps = (const unsigned char *)src;
	i = 0;
	if (dst > src)
	{
		while (i < len)
		{
			pd[len - 1 - i] = ps[len - 1 - i];
			i++;
		}
	}
	else
		ft_memcpy(pd, ps, len);
	return (dst);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*nd;
	const unsigned char	*ns;
	size_t				i;

	if (dst == src || n == 0)
		return (dst);
	nd = (unsigned char *)dst;
	ns = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		nd[i] = ns[i];
		i++;
	}
	return (nd);
}

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	size_t		len;

	len = ft_strlen(s);
	i = 0;
	while (i <= len)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*str;

	str = malloc(sizeof(char) * (n + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, n + 1);
	return (str);
}
