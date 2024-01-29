/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/26 05:46:17 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_BONUS_H
# define STRUCTS_BONUS_H
# include <stddef.h>

typedef struct s_coords
{
	int	x;
	int	y;
}			t_coords;

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
	double	hit_x;
	double	hit_y;
	float	intercept[2];
	float	step[2];
	int		hitted;
}				t_hit;

typedef struct s_player
{
	double	x;
	double	y;
	double	dx;
	double	dy;
	double	angle;
	double	rotate;
}				t_player;

typedef struct s_rays
{
	double	vx;
	double	vy;
	double	hx;
	double	hy;
	double	rx;
	double	ry;
	double	angle;
	double	fdist;
	double	hit_x;
	double	hit_y;
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

typedef struct s_draw_params
{
	t_image	*image;
	int		color;
	int		is_horizontal;
}			t_draw_params;

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
	int			mouse;
}				t_game;

#endif