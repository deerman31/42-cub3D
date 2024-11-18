/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:41:15 by ykusano           #+#    #+#             */
/*   Updated: 2023/10/14 19:21:29 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define W_PI 0.000000
# define N_PI 1.570796
# define E_PI 3.141593
# define S_PI 4.712389
# define MAX_PI 6.283185
# define FOV_RED 1.047198
# define GRID 64.00
# define WIN_H	512
# define WIN_W	640
# define ERROR "Error\n"
# define MALLOC_ER "Malloc Failed!"
# define INIT_ER "mlx_init Failed!"
# define IMG_ER "mlx_new_image Failed!"
# define WIN_ER "mlx_new_window Failed!"
# define IMG_ER "mlx_new_image Failed!"
# define XPM_ER "mlx_xpm_file_to_image Failed!"
# define TEXTURE_MISSING "Texture value is missing!"
# define ELEMENT_OVER_ER "Too many elements!"
# define ELEMENT_MISSING_ER "Missing elements!"
# define ELEMENT_DUP_ER "Duplicate elements!"
# define COLOR_MISSING "Color code value is missing!"
# define COLOR_INAPPROPRIATE "Color code value has values \
other than numbers and commas!"
# define COLOR_COMMAS "Color code value must consist of 3 \
numbers separated by commas!"
# define COLOR_COMMAS2 "Color code must be 3 digits separated \
by 2 commas!"
# define COLOR_OVER "Value of colorcode is overflowing!"
# define COLOR_REQ "Color code requires 3 numbers!"
# define MAP_BIG "Map is too large!"
# define MAP_INAP "Value other than 10 NSWE spaces exists in MAP!"
# define MAP_DUP "MAP has duplicate NSWE values!"
# define MAP_P_NO "No players on the MAP!"
# define MAP_WALL_OFF "Map is not enclosed by walls!"
# define PLAYER_WALL_OFF "Player is not inside the wall!"
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_W 119
# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define H 0
# define V 1

#endif
