/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 05:04:58 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/18 16:50:53 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	init_map(t_config **input, t_map **map)
{
	*map = malloc(sizeof(t_map));
	if (!*map)
		return ;
	(*map)->floor = (*input)->floor_color;
	(*map)->ceiling = (*input)->ceiling_color;
	(*map)->east = ft_strdup((*input)->tex.east_path);
	(*map)->west = ft_strdup((*input)->tex.west_path);
	(*map)->north = ft_strdup((*input)->tex.north_path);
	(*map)->south = ft_strdup((*input)->tex.south_path);
}
