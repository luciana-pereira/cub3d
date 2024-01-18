/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 04:36:56 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/18 15:46:16 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	move_player_verify_coords(t_game *game, float x, float y)
{
	if (!verify_coords_elements(game->map, x, y, 1))
	{
		game->player->x = x;
		game->player->y = y;
	}
}

static void	calculate_new_coordinates(t_game *game, float xy[2], float step, \
												int camera_control)
{
	if (!camera_control)
	{
		xy[0] = game->player->x + cos(game->player->angle) * step;
		xy[1] = game->player->y + sin(game->player->angle) * step;
	}
	else
	{
		xy[0] = game->player->x + cos(game->player->angle - M_PI / 2) * step;
		xy[1] = game->player->y + sin(game->player->angle - M_PI / 2) * step;
	}
}

void	move_player(t_game *game, int walk, int camera_control)
{
	float	step;
	float	xy[2];

	step = (walk * 8) + 3;
	calculate_new_coordinates(game, xy, step, camera_control);
	move_player_verify_coords(game, xy[0], xy[1]);
}
