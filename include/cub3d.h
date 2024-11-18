/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:41:01 by ykusano           #+#    #+#             */
/*   Updated: 2023/10/14 18:45:06 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdbool.h>
# include <math.h>
# include <string.h>
# include <limits.h>
# include "../minilibx/mlx.h"
# include "define.h"
# include "proto_type.h"

typedef enum e_mark
{
	NO,
	WE,
	EA,
	SO,
	F,
	C,
}		t_mark;

typedef enum e_dir
{
	NORTH,
	EAST,
	SOUTH,
	WEST,
	NONE,
}		t_dir;

typedef struct s_coord
{
	double	x;
	double	y;
}t_coord;

typedef struct s_vector
{
	double			red;
}t_vector;

typedef struct s_loca
{
	t_coord		coord;
	t_vector	vector;
}t_loca;

typedef struct s_map
{
	char			**map;
	size_t			width;
	size_t			height;
	size_t			player_x;
	size_t			player_y;
	double			angle;
	char			*n_path;
	char			*s_path;
	char			*w_path;
	char			*e_path;
	unsigned int	f_color;
	unsigned int	c_color;
}t_map;

typedef struct s_mlx
{
	void	*window;
	void	*mlx;
	void	*width;
	void	*height;
}t_mlx;

typedef struct s_ray
{
	struct s_world	*world;
	t_coord			h_offset;
	t_coord			v_offset;
	t_coord			coord;
	t_coord			h_cross_p;
	t_coord			v_cross_p;
	double			wall_dis;
	t_dir			dir[2];
	t_vector		vec;
	double			wall_height;
	double			hit_point;
	t_dir			wall_dir;
	double			perpe_line;

	int				start;
	int				end;
	double			step;
	double			tex_pos;
	int				tex_x;
	int				tex_y;
}t_ray;

typedef struct s_dir_dis
{
	double	north;
	double	south;
	double	west;
	double	east;
}t_dir_dis;

typedef struct s_texture{
	t_dir			direction;
	void			*wall_texture;
	unsigned int	*data;
	int				width;
	int				height;
	int				bits;
	int				lines;
	int				endian;
}t_texture;

typedef struct s_world
{
	t_ray			*rays;
	size_t			num_rays;
	t_map			map;
	double			fov;
	t_loca			loca;
	t_mlx			mlx;
	t_dir_dis		dir_dis;
	unsigned int	*data;
	void			*image;
	int				bits;
	int				lines;
	int				endian;
	int				floor_color;
	int				ceiling_color;
	t_texture		texture[4];
}t_world;

#endif
