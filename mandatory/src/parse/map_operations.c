/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/19 14:12:08 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	**copy_map(t_map *map)
{
	int	**duplicate;
	int	x;
	int	y;

	y = 0;
	duplicate = malloc(sizeof(int *) * map->y / 64);
	while (y < map->y / 64)
	{
		x = 0;
		duplicate[y] = malloc(sizeof(int) * map->x / 64);
		while (x < map->x / 64)
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
	t_lst	*new;

	init_map(input, map);
	if (!*map)
		return ;
	new = (t_lst *)malloc(sizeof(t_lst));
	new->next = NULL;
	new->content = NULL;
	(*map)->map = read_map(fd, input, new);
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

void	load_map(t_config **input, t_map **map)
{
	if (!read_and_process_file(input)
		|| (verify_textures(*input) == -1)
		|| (verify_colors(*input) == -1))
	{
		free_input(*input);
		*map = NULL;
		return ;
	}
	init_and_generate_map((*input)->fd, input, map);
}
