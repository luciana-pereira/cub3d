/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 23:35:36 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/26 05:50:09 by lucperei         ###   ########.fr       */
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
	t_coords		player_pos;
	t_coords		next_pos;
	t_draw_params	draw_params;

	calculate_player_positions(game, &player_pos, &next_pos);
	draw_params.image = &game->img;
	draw_params.color = COLOR_RED;
	draw_circle(&game->img, player_pos.x, player_pos.y, 3);
	draw_row(player_pos, next_pos, &draw_params);
	draw_rays(game, game->rays);
}
