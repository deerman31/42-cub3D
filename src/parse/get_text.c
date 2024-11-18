/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:46:19 by ykusano           #+#    #+#             */
/*   Updated: 2023/10/14 17:46:21 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*join(char *str, char *buf)
{
	const size_t	slen = ft_strlen(str);
	const size_t	blen = ft_strlen(buf);
	char			*ptr;

	ptr = malloc(sizeof(char) * (slen + blen + 1));
	if (ptr == NULL)
	{
		free(str);
		return (NULL);
	}
	ft_strlcpy(ptr, str, slen + 1);
	ft_strlcat(ptr, buf, slen + blen + 1);
	free(str);
	return (ptr);
}

static char	*get_text2(int fd)
{
	char	buf[10001];
	int		r_n;
	char	*str;

	str = "";
	r_n = 1;
	while (r_n != 0)
	{
		r_n = read(fd, buf, 10000);
		if (r_n < 0)
		{
			if (str[0] != '\0')
				free(str);
			printf("%s%s\n", ERROR, strerror(errno));
			exit (EXIT_FAILURE);
		}
		buf[r_n] = '\0';
		if (str[0] == '\0')
			str = ft_strdup(buf);
		else
			str = join(str, buf);
		if (str == NULL)
			return (NULL);
	}
	return (str);
}

char	*get_text(char *text)
{
	char	*str;
	int		fd;

	fd = open(text, O_RDONLY);
	if (fd < 0)
	{
		printf("%s%s\n", ERROR, strerror(errno));
		return (NULL);
	}
	str = get_text2(fd);
	if (str == NULL)
		printf("%s%s\n", ERROR, MALLOC_ER);
	close(fd);
	return (str);
}
