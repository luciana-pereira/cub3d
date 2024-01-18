/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 22:39:11 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/18 15:23:25 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	scanline_fill(int **duplicate, int x, int y, t_map *map);

static bool	is_visited(int cell_value)
{
	return (cell_value == 1 || cell_value == 3 || cell_value == 2);
}

static void	fill_line_above(int **duplicate, int lr[2], int y, t_map *map)
{
	int	index;

	index = lr[0] + 1;
	while (index < lr[1])
	{
		if (!is_visited(duplicate[y - 1][index]))
			scanline_fill(duplicate, index, y - 1, map);
		index++;
	}
}

static void	fill_line_below(int **duplicate, int lr[2], int y, t_map *map)
{
	int		count;

	count = lr[0] + 1;
	while (count < lr[1])
	{
		if (!is_visited(duplicate[y + 1][count]))
			scanline_fill(duplicate, count, y + 1, map);
		count++;
	}
}

void	scanline_fill(int **duplicate, int x, int y, t_map *map)
{
	int	lr[2];

	lr[0] = x;
	while (lr[0] >= 0 && !is_visited(duplicate[y][lr[0]])
		&& !(x == 0 || y == 0 || x == (map->x / 64) - 1
		|| y == (map->y / 64) - 1))
	{
		duplicate[y][lr[0]] = 3;
		lr[0]--;
	}
	lr[1] = x + 1;
	while (lr[1] < (map->x / 64) && !is_visited(duplicate[y][lr[1]])
		&& !(x == 0 || y == 0 || x == (map->x / 64) - 1
		|| y == (map->y / 64) - 1))
	{
		duplicate[y][lr[1]] = 3;
		lr[1]++;
	}
	if (y > 0)
		fill_line_above(duplicate, lr, y, map);
	if (y < (map->y / 64) - 1)
		fill_line_below(duplicate, lr, y, map);
}

void	scanline_flood_fill(int **duplicate, int x, int y, t_map *map)
{
	if (y >= 0 && x >= 0 && y < (map->y / 64) && x < (map->x / 64)
		&& !is_visited(duplicate[y][x]))
		scanline_fill(duplicate, x, y, map);
}
