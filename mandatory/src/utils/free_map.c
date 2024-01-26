/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:53:33 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/25 15:09:26 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_map(t_map *map)
{
	free(map->west);
	free(map->north);
	free(map->south);
	free(map->east);
	free_2d_array(map->map, map->y / 64);
	free(map);
}

void	free_map_lines(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
	}
}
