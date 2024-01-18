/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/18 13:26:27 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"
#include "../../includes/buttons_bonus.h"
#include <stdio.h>

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

// /**
//  * @brief Atualiza a direção do jogador com base nos eventos do mouse.
//  *
//  * Esta função é responsável por ajustar a direção do jogador em resposta aos eventos
//  * de movimento do mouse. Se o botão direito do mouse for pressionado, a direção do
//  * jogador é incrementada com a velocidade de rotação definida por TURN_SPEED. Se o botão
//  * esquerdo for pressionado, a direção é decrementada com a mesma velocidade. A função
//  * normaliza então a direção para garantir que permaneça no intervalo [0, 2*PI).
//  *
//  * @param keycode Código do botão do mouse pressionado.
//  * @param game Ponteiro para a estrutura principal do jogo.
//  */


/**
 * @brief Manipula eventos de mouse para rotação do jogador.
 *
 * Esta função realiza operações específicas relacionadas à rotação do jogador no contexto do jogo.
 * Se indicar movimento para a direita ou esquerda, a rotação do jogador é ajustada de acordo.
 *
 * @param g Ponteiro para a estrutura principal do jogo.
 * @return 0 para indicar que o evento foi tratado corretamente.
 */
int	mouse_hook(int x, int y, void *g)
{
	t_game *game;

	game = (t_game *)g;
	(void)y;
	if(game->mouse)
		return(0);
	if (x > WIN_W / 2)
		game->player->angle += TURN_SPEED / 3;
	else if (x < WIN_W / 2)
		game->player->angle += -1 * TURN_SPEED / 3;
	game->player->angle = fix_ang(game->player->angle);
	mlx_mouse_move(game->p_mlx, game->p_win, WIN_W / 2, WIN_H / 2);
	return (0);
}

int	mouse_click(int click, int x, int y, void *g)
{
	t_game *game;
	
	game = (t_game *)g;
	(void)x;
	(void)y;
	if(click == MOUSE_LEFT)
		game->mouse = !game->mouse;
	return (0);
}
