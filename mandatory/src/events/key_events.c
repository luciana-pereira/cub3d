/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 04:29:47 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/17 11:14:32 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/buttons.h"

int	key_press(int key, t_game *game)
{
	if (key == RIGHT || key == D_KEY || key == LEFT || key == A_KEY)
	{
		if (key == RIGHT || key == D_KEY)
			game->player->angle += TURN_SPEED;
		if (key == LEFT || key == A_KEY)
			game->player->angle += -1 * TURN_SPEED;
		game->player->angle = fix_ang(game->player->angle);
	}
	if (key == W_KEY || key == UP)
		move_player(game, 2, 0);
	if (key == S_KEY || key == DOWN)
		move_player(game, -2, 0);
	if (key == ESC)
	{
		if (game)
			free_game(game);
		exit(0);
	}
	return (0);
}
