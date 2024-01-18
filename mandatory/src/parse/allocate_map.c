/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:33:05 by luizedua          #+#    #+#             */
/*   Updated: 2024/01/18 15:34:19 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	**allocate_map_memory(t_config **input)
{
	int	**map;

	map = NULL;
	if ((*input)->height > 0)
		map = (int **)malloc(sizeof(int *) * (*input)->height);
	return (map);
}
