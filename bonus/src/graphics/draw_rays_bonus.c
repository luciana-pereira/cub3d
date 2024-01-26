/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/26 05:50:24 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void	draw_ray_segment(t_game *game, t_rays ray)
{
	t_coords		coords_ray;
	t_coords		ray_hit;
	t_draw_params	draw_params;

	coords_ray.x = floor(ray.rx * 0.2);
	coords_ray.y = floor(ray.ry * 0.2);
	ray_hit.x = floor(ray.hit_x * 0.2);
	ray_hit.y = floor(ray.hit_y * 0.2);
	draw_params.image = &game->img;
	draw_params.color = COLOR_WHITE;
	draw_row(coords_ray, ray_hit, &draw_params);
}

void	draw_rays(t_game *game, t_rays *rays)
{
	int	col;

	col = 0;
	while (col < game->num_rays)
	{
		draw_ray_segment(game, rays[col]);
		col++;
	}
}
