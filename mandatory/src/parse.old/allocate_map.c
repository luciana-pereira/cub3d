/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:20:18 by luizedua          #+#    #+#             */
/*   Updated: 2024/01/25 15:09:11 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	**allocate_map_memory(t_config **input)
{
	int	**map;

	map = NULL;
	if ((*input)->height > 0)
		map = (int **)malloc(sizeof(int *) * ((*input)->height + 1));
	if (!map)
		return (NULL);
	return (map);
}
