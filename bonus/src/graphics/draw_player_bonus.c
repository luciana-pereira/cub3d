/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 23:35:36 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/18 16:28:34 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void	calculate_player_positions(t_game *game, t_coords *player_pos, \
										t_coords *next_pos)
{
	player_pos->x = floor(game->player->x * 0.2);
	player_pos->y = floor(game->player->y * 0.2);
	next_pos->x = floor(game->player->x * 0.2 + cos(game->player->angle) * 10);
	next_pos->y = floor(game->player->y * 0.2 + sin(game->player->angle) * 10);
}

void	draw_player(t_game *game)
{
	t_coords	player_pos;
	t_coords	next_pos;

	calculate_player_positions(game, &player_pos, &next_pos);
	draw_circle(&game->img, player_pos.x, player_pos.y, 3);
	draw_row(&game->img, player_pos, next_pos, COLOR_RED);
	draw_rays(game, game->rays);
}
