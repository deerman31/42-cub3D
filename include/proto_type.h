/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto_type.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:41:26 by ykusano           #+#    #+#             */
/*   Updated: 2023/10/14 17:41:30 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_TYPE_H
# define PROTO_TYPE_H

# include "cub3d.h"

typedef struct s_world	t_world;
typedef struct s_ray	t_ray;
typedef struct s_map	t_map;

void		init(t_world *world);
void		set_ray(t_world *world, t_ray *ray, double angle);
bool		texture_set(t_world *world);
char		*get_text(char *text);
void		map_free(char **map);
char		**get_map(char *text);
bool		set_map(t_world *world, char *file_name);
void		game_close(t_world *world);
double		angle_to_radians(double angle);
double		wall_dis_cal(double x1, double y1, double x2, double y2);
double		red_reset(double red);
bool		arg_check(int argc, char **argv);
void		dis_check(t_world *world);
void		first_cross(t_world *world, t_ray *ray);
int			game_play(t_world *world);
int			key_op(int keycode, t_world *world);
int			game_end(t_world *world);
void		buf_set(t_ray *ray, size_t x);
void		draw(t_world *world);
void		offset(t_ray *ray, double red);
void		dir_dis(t_world *world);
void		cross_dis(t_world *world, t_ray *ray);
void		texture_free(t_world *world, size_t len);
bool		parse(t_world *world);
bool		element_set(t_map *map_info);
bool		re_map(t_map *map, size_t i);
bool		element_num_check(t_world *world, size_t *index);
bool		map_mark_check(t_map *map_info);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strchr(const char *s, int c);
size_t		vers_strlen(const char *s, const char *end_s);
bool		start_end_get(char *str, size_t *start, size_t *end, char *trim);
char		*ft_strndup(const char *s1, size_t n);
void		*ft_memset(void *b, int c, size_t len);
void		set_player(t_world *world);
void		dfs(char **map, size_t y, size_t x, t_world *world);
void		element_free(t_map *map);
bool		element_value_check(char **map);
int			num_set(char dir, t_ray *ray);
char		hv_check(t_ray *ray);

#endif
