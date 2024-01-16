/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 04:36:56 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/13 21:47:49 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * @brief Verifica as coordenadas antes de mover o jogador.
 *
 * Esta função verifica se as novas coordenadas especificadas estão dentro dos limites
 * permitidos pelo mapa. Se estiverem, atualiza as coordenadas do jogador.
 *
 * @param game Ponteiro para a estrutura principal do jogo.
 * @param x Nova coordenada x proposta para o jogador.
 * @param y Nova coordenada y proposta para o jogador.
 */
static void	move_player_verify_coords(t_game *game, double x, double y)
{
	if (!verify_coords_elements(game->map, x, y, 1))
	{
		game->player->x = x;
		game->player->y = y;
	}
}

/**
 * @brief Calcula as novas coordenadas do jogador com base nos parâmetros fornecidos.
 *
 * Esta função calcula as novas coordenadas do jogador com base no ângulo da câmera,
 * na velocidade de caminhada e no controle da câmera.
 *
 * @param game Ponteiro para a estrutura principal do jogo.
 * @param x Ponteiro para a variável que armazenará a nova coordenada x do jogador.
 * @param y Ponteiro para a variável que armazenará a nova coordenada y do jogador.
 * @param step Velocidade de caminhada multiplicada por um fator.
 * @param camera_control Flag que indica se o controle da câmera está ativado.
 */
static void	calculate_new_coordinates(t_game *game, double *x, double *y, float step, int camera_control)
{
	if (!camera_control)
	{
		*x = game->player->x + cos(game->player->angle) * step;
		*y = game->player->y + sin(game->player->angle) * step;
	}
	else
	{
		*x = game->player->x + cos(game->player->angle - M_PI / 2) * step;
		*y = game->player->y + sin(game->player->angle - M_PI / 2) * step;
	}
}

/**
 * @brief Move o jogador na direção especificada.
 *
 * Esta função move o jogador em uma direção específica com base nos parâmetros fornecidos.
 * O deslocamento é calculado com base na velocidade de caminhada e no controle da câmera.
 *
 * @param game Ponteiro para a estrutura principal do jogo.
 * @param walk Valor que controla a velocidade de caminhada.
 * @param camera_control Flag que indica se o controle da câmera está ativado.
 */
void	move_player(t_game *game, int walk, int camera_control)
{
	float	step;
	double	x;
	double	y;

	step = (walk * 8) + 3;
	calculate_new_coordinates(game, &x, &y, step, camera_control);
	move_player_verify_coords(game, x, y);
	}
