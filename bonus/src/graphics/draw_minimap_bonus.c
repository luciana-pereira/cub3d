/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:57:55 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/18 01:40:18 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	draw_map_row(t_game *game, t_map *map, t_coords map_pos, int sq_size);

/**
 * @brief Renderiza a cena do jogo, incluindo o mini-mapa.
 *
 * Esta função realiza o processo de renderização da cena do jogo, o qual
 * abrange a geração do plano de fundo representando o mini-mapa. Para cada
 * posição no mapa principal, calcula as coordenadas correspondentes no mini-mapa
 * e desenha um quadrado com base nas informações do mapa. Utiliza as funções
 * auxiliares `draw_map_row` e `draw_map_element`.
 *
 * @param game Ponteiro para a estrutura principal do jogo.
 * @param map Ponteiro para a estrutura que contém informações sobre o mapa.
 */
void	draw_mini_map(t_game *game, t_map *map)
{
	t_coords	map_pos;

	map_pos.y = 0;
	while (map_pos.y < map->y)
	{
		draw_map_row(game, map, map_pos, (64 * 0.2));
		map_pos.y += 64;
	}
	draw_player(game);
}

/**
 * @brief Desenha um quadrado colorido em uma imagem.
 *
 * Esta função desenha um quadrado colorido em uma imagem representada pela
 * estrutura t_image. O ponto de partida do quadrado é especificado pelas
 * coordenadas em t_coords 'start', e o tamanho do quadrado é dado pelo
 * parâmetro 'sq_size'. A cor do quadrado é determinada pelo parâmetro 'color'.
 *
 * @param image Ponteiro para a estrutura de imagem onde o quadrado será desenhado.
 * @param start Coordenadas do ponto de partida do quadrado.
 * @param sq_size Tamanho do lado do quadrado.
 * @param color Cor do quadrado a ser desenhado.
 */
static void	draw_colorful_square(t_image *image, t_coords start, int sq_size, int color)
{
	int	x;
	int	y;

	x = start.x;
	while (x <= sq_size + start.x)
	{
		y = start.y;
		while (y <= sq_size + start.y)
		{
			paint_img(image, x, y, color);
			y++;
		}
		x++;
	}
}

/**
 * @brief Desenha um elemento do mini-mapa.
 *
 * Esta função desenha um elemento individual do mini-mapa com base nas
 * coordenadas fornecidas e nas informações do mapa. Utiliza a função
 * `verify_coords_elements` para determinar a cor do quadrado no mini-mapa.
 *
 * @param game Ponteiro para a estrutura principal do jogo.
 * @param map_pos Estrutura que contém as coordenadas da posição no mapa principal.
 * @param sq_size Tamanho do quadrado a ser desenhado no mini-mapa.
 */
static void	draw_map_element(t_game *game, t_coords map_pos, int sq_size)
{
	t_coords	mini_pos;

	mini_pos.x = map_pos.x * 0.2;
	mini_pos.y = map_pos.y * 0.2;
	if (verify_coords_elements(game->map, map_pos.x, map_pos.y, 1))
		draw_colorful_square(&game->img, mini_pos, sq_size, COLOR_DARK_GRAY);
	else if (verify_coords_elements(game->map, map_pos.x, map_pos.y, 0))
		draw_colorful_square(&game->img, mini_pos, sq_size, COLOR_MEDIUM_GRAY);
}

/**
 * @brief Desenha uma linha do mini-mapa.
 *
 * Esta função desenha uma linha no mini-mapa, percorrendo as posições
 * horizontais do mapa principal. Utiliza a função auxiliar `draw_map_element`
 * para desenhar cada elemento do mini-mapa.
 *
 * @param game Ponteiro para a estrutura principal do jogo.
 * @param map Ponteiro para a estrutura que contém informações sobre o mapa.
 * @param map_pos Estrutura que contém as coordenadas da posição no mapa principal.
 * @param sq_size Tamanho do quadrado a ser desenhado no mini-mapa.
 */
void	draw_map_row(t_game *game, t_map *map, t_coords map_pos, int sq_size)
{
	map_pos.x = 0;
	while (map_pos.x < map->x)
	{
		draw_map_element(game, map_pos, sq_size);
		map_pos.x += 64;
	}
}
