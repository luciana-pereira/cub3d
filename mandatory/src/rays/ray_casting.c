/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/18 15:23:35 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_facing(float angle, int direction)
{
	if (direction == 0)
		return (angle > 0 && angle < M_PI);
	else if (direction == 1)
		return (!is_facing(angle, 0));
	else if (direction == 2)
		return (angle < 0.5 * M_PI || angle > 1.5 * M_PI);
	else if (direction == 3)
		return (!is_facing(angle, 2));
	return (0);
}

static void	init_ray_directions(t_rays *ray, float angle)
{
	ray->angle = angle;
	ray->vy = is_facing(ray->angle, 0);
	ray->vx = is_facing(ray->angle, 1);
	ray->hx = is_facing(ray->angle, 2);
	ray->hy = is_facing(ray->angle, 3);
}

void	init_ray(t_rays *ray, t_player *player, float angle)
{
	init_ray_directions(ray, angle);
	ray->rx = player->x;
	ray->ry = player->y;
	ray->fdist = 0;
	ray->hit_x = 0;
	ray->hit_y = 0;
	ray->is_hit = 0;
}

void	cast_and_generate_projection(t_game *game)
{
	float	angle;
	int		pixel_col;
	int		top_pixel;
	int		bottom_pixel;

	pixel_col = 0;
	angle = game->player->angle - 0.523599;
	while (pixel_col < game->num_rays)
	{
		angle = fix_ang(angle);
		init_ray(&game->rays[pixel_col], game->player, angle);
		calc_vert_ray_intercept(game, game->player, &game->rays[pixel_col]);
		angle += (double)FOV / (double)game->num_rays;
		top_pixel = calculate_position(game, pixel_col, 1);
		bottom_pixel = calculate_position(game, pixel_col, 0);
		draw_wall(game, pixel_col, top_pixel, bottom_pixel);
		pixel_col++;
	}
}
