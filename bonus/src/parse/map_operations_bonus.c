/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_operations_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/24 15:06:06 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"
#include <stdio.h>

int	**copy_map(t_map *map)
{
	int	**duplicate;
	int	x;
	int	y;

	y = 0;
	duplicate = malloc(sizeof(int *) * (map->y / 64));
	while (y < map->y / 64)
	{
		x = 0;
		duplicate[y] = malloc(sizeof(int) * (map->x / 64));
		while (x < map->x / 64 && map->map[y] != NULL)
		{
			duplicate[y][x] = map->map[y][x];
			x++;
		}
		y++;
	}
	return (duplicate);
}

static void	init_and_generate_map(int fd, t_config **input, t_map **map)
{
	init_map(input, map);
	if (!*map)
		return ;
	(*map)->map = read_map(fd, input);
	if (!(*map)->map)
	{
		free_map(*map);
		*map = NULL;
		return ;
	}
	(*map)->y = (*input)->height * 64;
	(*map)->x = (*input)->width * 64;
	(*map)->plane = ((float)(*map)->x / 2) / tan(FOV / 2);
}

int	load_map(t_config **input, t_map **map)
{
	if (!read_and_process_file(input)
		|| (verify_textures(*input) == -1)
		|| (verify_colors(*input) == -1))
	{
		free_input(*input);
		*map = NULL;
		return (-1);
	}
	init_and_generate_map((*input)->fd, input, map);
	if (*map == NULL)
	{
		map = NULL;
		return (-1);
	}
	return (0);
}
