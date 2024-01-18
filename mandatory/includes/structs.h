/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/18 14:03:44 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_tex
{
	int		north;
	int		south;
	int		west;
	int		east;
	char	*north_path;
	char	*south_path;
	char	*west_path;
	char	*east_path;
}				t_tex;

typedef struct s_config
{
	int		fd;
	int		px;
	int		py;
	int		player;
	int		floor;
	int		ceiling;
	int		player_dir;
	int		floor_color;
	int		ceiling_color;
	size_t	height;
	size_t	width;
	t_tex	tex;
}				t_config;

typedef struct s_hit
{
	float	distance;
	float	hit_x;
	float	hit_y;
	float	intercept[2];
	float	step[2];
	int		hitted;
}				t_hit;

typedef struct s_player
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	angle;
	float	rotate;
}				t_player;

typedef struct s_rays
{
	float	vx;
	float	vy;
	float	hx;
	float	hy;
	float	rx;
	float	ry;
	float	angle;
	float	fdist;
	float	hit_x;
	float	hit_y;
	int		is_hit;
}				t_rays;

typedef struct s_image
{
	void	*p_img;
	char	*i_add;
	int		*data;
	int		bpp;
	int		size_line;
	int		endian;
}				t_image;

typedef struct s_map
{
	int		x;
	int		y;
	int		**map;
	int		floor;
	int		ceiling;
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	float	plane;
}				t_map;

typedef struct s_game
{
	t_map		*map;
	t_image		img;
	t_image		west;
	t_image		east;
	t_image		north;
	t_image		south;
	t_rays		*rays;
	void		*p_mlx;
	void		*p_win;
	t_player	*player;
	int			num_rays;
}				t_game;

#endif