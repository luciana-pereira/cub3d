/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:57:55 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/18 16:30:09 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	draw_map_row(t_game *game, t_map *map, t_coords map_pos, int sq_size);

void	draw_mini_map(t_game *game, t_map *map)
{
	t_coords	map_pos;

	map_pos.y = 0;
	while (map_pos.y < map->y)
	{
		draw_map_row(game, map, map_pos, (64 * 0.2));
		map_pos.y += 64;
	}
	draw_player(game);
}

static void	draw_colorful_square(t_image *image, t_coords start, int sq_size, \
									int color)
{
	int	x;
	int	y;

	x = start.x;
	while (x <= sq_size + start.x)
	{
		y = start.y;
		while (y <= sq_size + start.y)
		{
			paint_img(image, x, y, color);
			y++;
		}
		x++;
	}
}

static void	draw_map_element(t_game *game, t_coords map_pos, int sq_size)
{
	t_coords	mini_pos;

	mini_pos.x = map_pos.x * 0.2;
	mini_pos.y = map_pos.y * 0.2;
	if (verify_coords_elements(game->map, map_pos.x, map_pos.y, 1))
		draw_colorful_square(&game->img, mini_pos, sq_size, COLOR_DARK_GRAY);
	else if (verify_coords_elements(game->map, map_pos.x, map_pos.y, 0))
		draw_colorful_square(&game->img, mini_pos, sq_size, COLOR_MEDIUM_GRAY);
}

void	draw_map_row(t_game *game, t_map *map, t_coords map_pos, int sq_size)
{
	map_pos.x = 0;
	while (map_pos.x < map->x)
	{
		draw_map_element(game, map_pos, sq_size);
		map_pos.x += 64;
	}
}
