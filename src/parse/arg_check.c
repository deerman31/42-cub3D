/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:45:22 by ykusano           #+#    #+#             */
/*   Updated: 2023/10/14 17:45:24 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	cub_check(char *file_path)
{
	const char	cub[5] = ".cub";
	char		*s;

	s = ft_strrchr(file_path, '.');
	if (s == NULL)
		return (false);
	if (ft_strlen(s) != 4)
		return (false);
	if (ft_strncmp(cub, s, 4) != 0)
		return (false);
	return (true);
}

bool	arg_check(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("%sThere is only one argument!\n", ERROR);
		return (false);
	}
	if (!cub_check(argv[1]))
	{
		printf("%sFile extension must be \".cub\"!\n", ERROR);
		return (false);
	}
	return (true);
}
