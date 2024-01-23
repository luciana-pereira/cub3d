/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_processing_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/23 10:31:28 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	calculate_intercept(t_player *player, t_rays ray, t_hit *hit, char dir)
{
	float	diff;

	if (dir == 'h')
	{
		hit->intercept[1] = floor(player->y / 64) * 64;
		if (ray.vy)
			hit->intercept[1] += 64;
		if (ray.vx)
			hit->intercept[1] -= 0.0001;
		diff = hit->intercept[1] - player->y;
		hit->intercept[0] = player->x + (diff) / tan(ray.angle);
	}
	else if (dir == 'v')
	{
		hit->intercept[0] = floor(player->x / 64) * 64;
		if (ray.hx)
			hit->intercept[0] += 64;
		if (ray.hy)
			hit->intercept[0] -= 0.0001;
		diff = hit->intercept[0] - player->x;
		hit->intercept[1] = player->y + (diff) * tan(ray.angle);
	}
}

void	calculate_steps(t_rays ray, t_hit *hit, char direction)
{
	if (direction == 'h')
	{
		hit->step[1] = 64;
		if (ray.vx)
			hit->step[1] *= -1;
		hit->step[0] = 64 / tan(ray.angle);
		if ((ray.hy && hit->step[0] > 0)
			|| (ray.hx && hit->step[0] < 0))
			hit->step[0] *= -1;
	}
	else if (direction == 'v')
	{
		hit->step[0] = 64;
		if (ray.hy)
			hit->step[0] *= -1;
		hit->step[1] = 64 * tan(ray.angle);
		if ((ray.vx && hit->step[1] > 0)
			|| (ray.vy && hit->step[1] < 0))
			hit->step[1] *= -1;
	}
}

static int	check_collision(t_map *map, t_rays ray, t_hit *hit, char direction)
{
	float	coords[2];

	(void)ray;
	(void)direction;
	coords[0] = hit->hit_x;
	coords[1] = hit->hit_y;
	return (verify_coords_elements(map, coords[0], coords[1], 1));
}

void	increment_position(t_map *map, t_rays ray, t_hit *hit, char direction)
{
	hit->hitted = 0;
	hit->hit_x = hit->intercept[0];
	hit->hit_y = hit->intercept[1];
	while (hit->hit_x >= 0 && hit->hit_y < map->y && \
		((hit->hit_x < map->x && hit->hit_y >= 0 && direction == 'v') \
			|| (hit->hit_x < map->x && hit->hit_y > 0 && direction == 'h')))
	{
		if (check_collision(map, ray, hit, direction))
		{
			hit->hitted = 1;
			return ;
		}
		else
		{
			hit->hit_x += hit->step[0];
			hit->hit_y += hit->step[1];
		}
	}
	hit->hit_x = 0;
	hit->hit_y = 0;
}
