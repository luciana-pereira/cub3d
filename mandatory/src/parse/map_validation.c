/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/23 12:56:16 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_valid_duplicate(t_map *map, int **duplicate)
{
	int	x;
	int	y;
	int	pos;

	y = 0;
	while (y < map->y / 64)
	{
		x = 0;
		while (x < map->x / 64)
		{
			pos = duplicate[y][x];
			if (!((pos == 1 || pos == 0 || pos == 9) || \
				(pos == 5 || pos == 6 || pos == 7 || pos == 8) || \
					(pos == 3)))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	is_valid_map_path(t_map *map, int x, int y)
{
	int	**duplicate;

	if (!map->map)
		return (0);
	duplicate = copy_map(map);
	scanline_flood_fill(duplicate, x, y, map);
	if (!is_valid_duplicate(map, duplicate))
	{
		free_2d_array(duplicate, map->y / 64);
		return (print_error(INVALID_PATH));
	}
	free_2d_array(duplicate, map->y / 64);
	return (0);
}
