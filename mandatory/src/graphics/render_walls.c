/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/14 23:02:15 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * @brief Obtém a textura de impacto ao colidir com uma parede, com base na direção do raio.
 *
 * Esta função determina a textura a ser utilizada quando ocorre uma colisão com uma parede, com base na direção do raio.
 * Se a componente vertical do raio for diferente de zero, a textura associada à direção oeste é retornada e a flag 'invert' é ajustada para a inversão da textura.
 * Caso contrário, a textura associada à direção leste é retornada.
 *
 * @param game Ponteiro para a estrutura principal do jogo.
 * @param x Índice do raio.
 * @param invert Ponteiro para a flag que indica se a textura deve ser invertida.
 * @return A textura associada à colisão com a parede.
 */
t_image	get_hit_wall_texture(t_game *game, int x, int *invert)
{
	if (game->rays[x].hy)
	{
		*invert = (64 - 1);
		return game->west;
	}
	else
		return game->east;
}

/**
 * @brief Obtém a textura de não colisão com uma parede, com base na direção do raio.
 *
 * Esta função determina a textura a ser utilizada quando não ocorre colisão com uma parede, com base na direção do raio.
 * Se a componente horizontal do raio for diferente de zero, a textura associada à direção norte é retornada.
 * Caso contrário, a textura associada à direção sul é retornada e a flag 'invert' é ajustada para a inversão da textura.
 *
 * @param game Ponteiro para a estrutura principal do jogo.
 * @param x Índice do raio.
 * @param invert Ponteiro para a flag que indica se a textura deve ser invertida.
 * @return A textura associada à não colisão com a parede.
 */
t_image	get_miss_wall_texture(t_game *game, int x, int *invert)
{
	if (game->rays[x].vx)
		return game->north;
	else
	{
		*invert = (64 - 1);
		return game->south;
	}
}

/**
 * @brief Obtém a textura associada à colisão ou não colisão com uma parede, com base na flag 'is_hit' do raio.
 *
 * Esta função determina a textura a ser utilizada com base na informação de colisão ('is_hit') do raio.
 * Se o raio colidiu com uma parede, chama a função 'get_hit_wall_texture' para obter a textura correspondente.
 * Caso contrário, chama a função 'get_miss_wall_texture' para obter a textura de não colisão.
 * A flag 'invert' é ajustada de acordo com a textura retornada.
 *
 * @param game Ponteiro para a estrutura principal do jogo.
 * @param x Índice do raio.
 * @param invert Ponteiro para a flag que indica se a textura deve ser invertida.
 * @return A textura associada à colisão ou não colisão com a parede.
 */
t_image	get_wall_texture(t_game *game, int x, int *invert)
{
	if (game->rays[x].is_hit)
		return get_hit_wall_texture(game, x, invert);
	else
		return get_miss_wall_texture(game, x, invert);
}

/**
 * @brief Desenha uma fatia de parede na posição especificada na tela.
 *
 * Esta função desenha uma fatia de parede na posição (x, y) da tela do jogo. A textura da parede é obtida através da
 * função 'get_wall_texture', e a cor correspondente é extraída utilizando a função 'get_texture'. A fatia de parede é
 * então desenhada na imagem do jogo usando a função 'paint_img'.
 *
 * @param game Ponteiro para a estrutura principal do jogo.
 * @param x Coordenada x da posição na tela.
 * @param y Coordenada y da posição na tela.
 * @param invert Flag que indica se a textura deve ser invertida.
 */
static void	draw_wall_slice(t_game *game, int x, int y, int invert)
{
	int		color;
	int		coord[2];
	t_image	texture;

	coord[0] = x;
	coord[1] = y;
	texture = get_wall_texture(game, x, &invert);
	color = get_texture(game, texture, coord, invert);
	paint_img(&game->img, x, y, color);
}

/**
 * @brief Desenha uma parede verticalmente na tela, delimitada pelos pixels superior e inferior.
 *
 * Esta função desenha uma parede vertical na tela do jogo, percorrendo os pixels da coordenada superior até a coordenada inferior.
 * Para cada pixel dentro do intervalo especificado, a função chama 'draw_wall_slice' para desenhar a fatia de parede correspondente.
 * Verifica se a coordenada y está dentro dos limites da tela antes de desenhar a fatia de parede.
 *
 * @param game Ponteiro para a estrutura principal do jogo.
 * @param x Coordenada x da posição na tela.
 * @param top_pixel Coordenada y do pixel superior da parede.
 * @param bot_pixel Coordenada y do pixel inferior da parede.
 */
void	draw_wall(t_game *game, int x, int top_pixel, int bot_pixel)
{
	int	coord[2];

	coord[0] = x;
	coord[1] = top_pixel;
	while (coord[1] < bot_pixel)
	{
		if (coord[1] >= 0 && coord[1] <= WIN_H)
		{
			int invert = 0;
			draw_wall_slice(game, coord[0], coord[1], invert);
		}
		coord[1]++;
	}
}
