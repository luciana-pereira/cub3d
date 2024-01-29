/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/29 10:15:16 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"
#include "../../includes/buttons_bonus.h"

int	key_press(int key, t_game *game)
{
	if (key == RIGHT || key == LEFT)
	{
		if (key == RIGHT)
			game->player->angle += TURN_SPEED;
		if (key == LEFT)
			game->player->angle += -1 * TURN_SPEED;
		game->player->angle = fix_ang(game->player->angle);
	}
	if (key == W_KEY || key == UP)
		move_player(game, 2, 0);
	if (key == S_KEY || key == DOWN)
		move_player(game, -2, 0);
	if (key == A_KEY)
		move_player(game, 2, 1);
	if (key == D_KEY)
		move_player(game, -2, 1);
	if (key == ESC)
	{
		if (game)
			free_game(game);
		exit(0);
	}
	return (0);
}

int	mouse_hook(int x, int y, void *g)
{
	t_game	*game;

	game = (t_game *)g;
	(void)y;
	if (game->mouse)
		return (0);
	if (x > WIN_W / 2)
		game->player->angle += TURN_SPEED * 0.3;
	else if (x < WIN_W / 2)
		game->player->angle += -1 * TURN_SPEED * 0.3;
	game->player->angle = fix_ang(game->player->angle);
	mlx_mouse_move(game->p_mlx, game->p_win, WIN_W / 2, WIN_H / 2);
	return (0);
}

int	mouse_click(int click, int x, int y, void *g)
{
	t_game	*game;

	game = (t_game *)g;
	(void)x;
	(void)y;
	if (click == MOUSE_LEFT)
	{
		game->mouse = !game->mouse;
		mlx_mouse_hide(game->p_mlx, game->p_win);
	}
	return (0);
}
