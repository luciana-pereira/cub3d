/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:53:33 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/18 15:19:55 by luizedua         ###   ########.fr       */
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

void	free_map_lines(t_lst *map_line)
{
	t_lst	*aux;

	if (!map_line)
		return ;
	while (map_line->next)
	{
		aux = map_line;
		map_line = map_line->next;
		free(aux->content);
		free(aux);
	}
	free(map_line->content);
	free(map_line);
}
