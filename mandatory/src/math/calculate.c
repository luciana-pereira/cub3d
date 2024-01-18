/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/18 15:23:14 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	calculate_upper_position(int wall_height)
{
	int	vertical_posit_top;

	vertical_posit_top = (WIN_H / 2) - wall_height;
	if (vertical_posit_top < 0)
		vertical_posit_top = 0;
	return (vertical_posit_top);
}

static int	calculate_lower_position(int wall_height)
{
	int	start_position;

	start_position = (WIN_H / 2) + wall_height;
	if (start_position > WIN_H)
		start_position = WIN_H;
	return (start_position);
}

int	calculate_position(t_game *game, int col, int control)
{
	int	wall_height;

	wall_height = floor((64 / game->rays[col].fdist) * game->map->plane) / 2;
	if (control)
		return (calculate_upper_position(wall_height));
	else
		return (calculate_lower_position(wall_height));
}

int	calc_horizontal_disp(t_rays ray)
{
	if (ray.is_hit)
		return ((int)ray.hit_y % 64);
	else
		return ((int)ray.hit_x % 64);
}
