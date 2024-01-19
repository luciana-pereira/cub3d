/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 05:05:14 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/19 16:27:02 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	start_player(t_player *player, int x, int y, int dir)
{
	player->x = (x * 64) + 32;
	player->y = (y * 64) + 32;
	player->dx = 0;
	player->dy = 0;
	player->angle = dir * M_PI / 2;
}

int	init_player(t_player **player, int py, int px, char player_dir)
{
	*player = malloc(sizeof(t_player));
	if (*player == NULL)
		return (-1);
	start_player(*player, py, px, player_dir);
	return (0);
}
