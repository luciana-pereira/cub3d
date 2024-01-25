/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_config_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/25 14:07:27 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <stdio.h>

static int	handle_valid_element(char element, t_config **input, int x, int y)
{
	if (element != '0')
	{
		(*input)->px = x;
		(*input)->py = y;
		(*input)->player++;
	}
	if (element == SOUTH)
		(*input)->player_dir = DIR_SOUTH;
	else if (element == WEST)
		(*input)->player_dir = DIR_WEST;
	else if (element == NORTH)
		(*input)->player_dir = DIR_NORTH;
	else if (element == EAST)
		(*input)->player_dir = DIR_EAST;
	return (0);
}

int	get_element(char element, t_config **input, int x, int y)
{
	if (element == '1')
		return (1);
	if (element == SOUTH || element == NORTH || \
		element == WEST || element == EAST || element == '0')
		return (handle_valid_element(element, input, x, y));
	if (element == ' ')
		return (EMPTY);
	print_error(INVALID_CHARAC);
	return (-1);
}

int	verify_line(char *line)
{
	if (!ft_strncmp(line, "NO", 2) || \
		!ft_strncmp(line, "SO", 2) || \
		!ft_strncmp(line, "WE", 2) || \
		!ft_strncmp(line, "EA", 2) || \
		!ft_strncmp(line, "F ", 2) || \
		!ft_strncmp(line, "C ", 2))
	{
		return (1);
	}
	return (0);
}

int	verify_coords_elements(t_map *map, float x, float y, int flag)
{
	if (x < 0 || x > (float)map->x || y < 0 || y > (float)map->y)
		return (1);
	if (map->map[(int)floor(y / 64)][(int)floor(x / 64)] == flag)
		return (1);
	return (0);
}
