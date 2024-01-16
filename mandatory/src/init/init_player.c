/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 05:05:14 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/13 05:06:29 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * Inicia um jogador com a posição inicial, direção e ângulo especificados.
 *
 * @param x: coordenada x inicial do jogador.
 * @param y: coordenada y inicial do jogador.
 * @param dir: direção inicial do jogador (0 - norte, 1 - leste, 2 - sul, 3 - oeste).
 * @return Um ponteiro para a estrutura do jogador alocada dinamicamente.
 */
static void	start_player(t_player *player, int x, int y, int dir)
{
	player->x = x * 64;
	player->y = y * 64;
	player->dx = 0;
	player->dy = 0;
	player->angle = dir * M_PI / 2;
}

int init_player(t_player **player, int py, int px, char player_dir)
{
    *player = malloc(sizeof(t_player));
    if (*player == NULL)
        return (-1);
    start_player(*player, py, px, player_dir);
    return (0);
}
