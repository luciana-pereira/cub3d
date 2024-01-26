/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intercept_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/18 16:50:16 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void	update_ray_distances(t_rays *ray, t_hit *horz, t_hit *vert)
{
	if (horz->distance > vert->distance)
	{
		ray->fdist = vert->distance;
		ray->hit_x = vert->hit_x;
		ray->hit_y = vert->hit_y;
		ray->is_hit = 1;
	}
	else
	{
		ray->fdist = horz->distance;
		ray->hit_x = horz->hit_x;
		ray->hit_y = horz->hit_y;
		ray->is_hit = 0;
	}
}

static float	calc_dist_player(t_player *p, t_hit h)
{
	if (h.hitted)
		return (distance(p->x, p->y, h.hit_x, h.hit_y));
	else
		return (FLT_MAX);
}

t_hit	cal_coord_intercept(t_game *game, t_rays ray, char dir)
{
	t_hit	coord;

	calculate_intercept(game->player, ray, &coord, dir);
	calculate_steps(ray, &coord, dir);
	increment_position(game->map, ray, &coord, dir);
	coord.distance = calc_dist_player(game->player, coord);
	return (coord);
}

void	find_wall(t_hit *h, t_hit *v, t_player *p, float angle)
{
	if (h->hitted)
		h->distance = h->distance * cos(p->angle - angle);
	else
		h->distance = FLT_MAX;
	if (v->hitted)
		v->distance = v->distance * cos(p->angle - angle);
	else
		v->distance = FLT_MAX;
}

void	calc_vert_ray_intercept(t_game *game, t_player *player, t_rays *ray)
{
	t_hit	horz;
	t_hit	vert;

	horz = cal_coord_intercept(game, *ray, 'h');
	vert = cal_coord_intercept(game, *ray, 'v');
	find_wall(&horz, &vert, player, ray->angle);
	update_ray_distances(ray, &horz, &vert);
}
