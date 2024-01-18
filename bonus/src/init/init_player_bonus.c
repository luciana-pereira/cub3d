/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 05:04:58 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/13 05:07:35 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/**
 * @brief Inicializa as propriedades iniciais do jogador.
 *
 * Esta função recebe um jogador, coordenadas x e y, e uma direção, e inicializa as propriedades do jogador.
 * As coordenadas x e y são multiplicadas por 64 para obter a posição em pixels. O vetor de direção (dx, dy) é definido como (0, 0),
 * e o ângulo do jogador é calculado com base na direção fornecida, convertido para radianos.
 *
 * @param player Ponteiro para a estrutura do jogador.
 * @param x Coordenada x inicial do jogador em células.
 * @param y Coordenada y inicial do jogador em células.
 * @param dir Direção inicial do jogador (0, 1, 2, 3 correspondendo a norte, leste, sul, oeste, respectivamente).
 */
static void	start_player(t_player *player, int x, int y, int dir)
{
	player->x = x * 64;
	player->y = y * 64;
	player->dx = 0;
	player->dy = 0;
	player->angle = dir * M_PI / 2;
}

/**
 * @brief Inicializa a estrutura do jogador com base nas coordenadas e na direção fornecidas.
 *
 * Esta função aloca dinamicamente a estrutura do jogador e a inicializa com as coordenadas e a direção fornecidas.
 * Se a alocação de memória falhar, a função retorna -1. Caso contrário, a função chama 'start_player' para
 * inicializar as propriedades do jogador com os parâmetros fornecidos e retorna 0.
 *
 * @param player Ponteiro para o ponteiro da estrutura do jogador.
 * @param py Coordenada y inicial do jogador em células.
 * @param px Coordenada x inicial do jogador em células.
 * @param player_dir Direção inicial do jogador ('N', 'E', 'S', 'W').
 * @return 0 em caso de sucesso, -1 em caso de falha na alocação de memória.
 */
int init_player(t_player **player, int py, int px, char player_dir)
{
	*player = malloc(sizeof(t_player));
	if (*player == NULL)
		return (-1);
	start_player(*player, py, px, player_dir);
	return (0);
}
