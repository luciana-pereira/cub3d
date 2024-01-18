/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/18 16:28:03 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

t_image	get_hit_wall_texture(t_game *game, int x, int *invert)
{
	if (game->rays[x].hy)
	{
		*invert = (64 - 1);
		return (game->west);
	}
	else
		return (game->east);
}

t_image	get_miss_wall_texture(t_game *game, int x, int *invert)
{
	if (game->rays[x].vx)
		return (game->north);
	else
	{
		*invert = (64 - 1);
		return (game->south);
	}
}

t_image	get_wall_texture(t_game *game, int x, int *invert)
{
	if (game->rays[x].is_hit)
		return (get_hit_wall_texture(game, x, invert));
	else
		return (get_miss_wall_texture(game, x, invert));
}

static void	draw_wall_slice(t_game *game, int x, int y, int invert)
{
	int		color;
	int		coord[2];
	t_image	texture;

	coord[0] = x;
	coord[1] = y;
	texture = get_wall_texture(game, x, &invert);
	color = get_texture(game, texture, coord, invert);
	paint_img(&game->img, x, y, color);
}

void	draw_wall(t_game *game, int x, int top_pixel, int bot_pixel)
{
	int	invert;
	int	coord[2];

	invert = 0;
	coord[0] = x;
	coord[1] = top_pixel;
	while (coord[1] < bot_pixel)
	{
		if (coord[1] >= 0 && coord[1] <= WIN_H)
		{
			draw_wall_slice(game, coord[0], coord[1], invert);
		}
		coord[1]++;
	}
}
