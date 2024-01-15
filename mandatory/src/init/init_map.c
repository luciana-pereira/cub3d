/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:03:34 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/13 21:38:01 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
