/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 23:35:36 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/18 05:51:15 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"


/**
 * @brief Calcula as posições do jogador atual e a próxima posição com base no ângulo.
 *
 * Esta função calcula as posições do jogador atual (representado por 'player_pos')
 * e a próxima posição do jogador (representado por 'next_pos') com base nas
 * coordenadas x e y armazenadas na estrutura do jogador em t_player e no ângulo
 * em que o jogador está virado.
 *
 * @param game Ponteiro para a estrutura principal do jogo.
 * @param player_pos Ponteiro para a estrutura de coordenadas do jogador atual.
 * @param next_pos Ponteiro para a estrutura de coordenadas da próxima posição do jogador.
 */
static void	calculate_player_positions(t_game *game, t_coords *player_pos, t_coords *next_pos)
{
	player_pos->x = floor(game->player->x * 0.2);
	player_pos->y = floor(game->player->y * 0.2);
	next_pos->x = floor(game->player->x * 0.2 + cos(game->player->angle) * 10);
	next_pos->y = floor(game->player->y * 0.2 + sin(game->player->angle) * 10);
}

/**
 * @brief Desenha a representação visual do jogador no mini-mapa.
 *
 * Esta função desenha a representação visual do jogador no mini-mapa. A posição
 * atual do jogador é obtida das coordenadas x e y armazenadas na estrutura do
 * jogador em t_player. A função calcula a próxima posição do jogador com base
 * no ângulo em que ele está virado e desenha uma linha que representa a direção
 * para a qual o jogador está olhando.
 *
 * @param game Ponteiro para a estrutura principal do jogo.
 */
void	draw_player(t_game *game)
{
	t_coords	player_pos;
	t_coords	next_pos;

	calculate_player_positions(game, &player_pos, &next_pos);
	draw_circle(&game->img, player_pos.x, player_pos.y, 3);
	draw_row(&game->img, player_pos, next_pos, COLOR_RED);
	draw_rays(game, game->rays);
}
