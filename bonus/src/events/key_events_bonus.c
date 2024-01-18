/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/07 18:42:01 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"
#include "../../includes/buttons_bonus.h"

/**
 * @brief Move o jogador na direção especificada.
 *
 * Esta função move o jogador em uma direção específica com base nos parâmetros fornecidos.
 * O deslocamento é calculado com base na velocidade de caminhada e no controle da câmera.
 *
 * @param game Ponteiro para a estrutura principal do jogo.
 * @param walk Valor que controla a velocidade de caminhada.
 * @param camera_control Flag que indica se o controle da câmera está ativado.
 *
 * @return Retorna 0 após o processamento da tecla.
 */
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
		move_player(game, 1, 0);
	if (key == S_KEY || key == DOWN)
		move_player(game, -1, 0);
	if (key == ESC)
	{
		if (game)
			free_game(game);
		exit(0);
	}
	return (0);
}

/**
 * @brief Atualiza a direção do jogador com base nos eventos do mouse.
 *
 * Esta função é responsável por ajustar a direção do jogador em resposta aos eventos
 * de movimento do mouse. Se o botão direito do mouse for pressionado, a direção do
 * jogador é incrementada com a velocidade de rotação definida por TURN_SPEED. Se o botão
 * esquerdo for pressionado, a direção é decrementada com a mesma velocidade. A função
 * normaliza então a direção para garantir que permaneça no intervalo [0, 2*PI).
 *
 * @param keycode Código do botão do mouse pressionado.
 * @param game Ponteiro para a estrutura principal do jogo.
 */
static void	rotate_player_mouse(int keycode, t_game *game)
{
	if (keycode == MOUSE_RIGHT)
		game->player->angle += TURN_SPEED;
	if (keycode == MOUSE_LEFT)
		game->player->angle += -1 * TURN_SPEED;
	game->player->angle = fix_ang(game->player->angle);
}

/**
 * @brief Manipula eventos de mouse para movimentação e rotação do jogador.
 *
 * Esta função é chamada em resposta a eventos de mouse, onde o código da tecla do mouse
 * é fornecido como argumento `key`. Com base nesse código, a função realiza operações
 * específicas relacionadas à movimentação e rotação do jogador no contexto do jogo.
 * Se a tecla do mouse indicar um movimento para cima, o jogador é movido para frente.
 * Se indicar um movimento para baixo, o jogador é movido para trás. Se indicar movimento
 * para a direita ou esquerda, a rotação do jogador é ajustada de acordo.
 *
 * @param key Código da tecla do mouse que acionou o evento.
 * @param x Coordenada x do ponteiro do mouse (não utilizado na função).
 * @param y Coordenada y do ponteiro do mouse (não utilizado na função).
 * @param game Ponteiro para a estrutura principal do jogo.
 * @return 0 para indicar que o evento foi tratado corretamente.
 */
int	mouse_hook(int key, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (key == MOUSE_UP)
		move_player(game, 1, 0);
	if (key == MOUSE_DOWN)
		move_player(game, -1, 0);
	if (key == MOUSE_RIGHT || key == MOUSE_LEFT)
		rotate_player_mouse(key, game);
	return (0);
}
