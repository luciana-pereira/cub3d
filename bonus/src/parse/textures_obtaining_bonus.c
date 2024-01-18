/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_obtaining_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:45:42 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/18 06:20:57 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/**
 * @brief Calcula as dimensões da parede na tela.
 *
 * Esta função calcula as dimensões da parede na tela com base nas informações do raio,
 * coordenadas e inversão especificadas. Atualiza o vetor 'offset' com as dimensões calculadas.
 *
 * @param game Ponteiro para a estrutura principal do jogo.
 * @param coord Vetor contendo as coordenadas [x, y] da tela.
 * @param invert Valor de inversão.
 * @param offset Ponteiro para o vetor que armazenará as dimensões calculadas [deslocamento, distância até o topo].
 */
void	cal_wall_dimension(t_game *game, int coord[2], int invert, int *offset)
{
	float	height;
	int		dist_to_top;

	height = (64 / game->rays[coord[0]].fdist) * game->map->plane;
	if (invert)
		offset[0] = (invert - calc_horizontal_disp(game->rays[coord[0]]));
	else
		offset[0] = calc_horizontal_disp(game->rays[coord[0]]);
	dist_to_top = coord[1] + (floor(height) / 2) - ((float)WIN_H / 2);
	offset[1] = dist_to_top * ((float)64 / floor(height));
}

/**
 * @brief Obtém a cor da textura com base nas dimensões especificadas.
 *
 * Esta função obtém a cor da textura com base nas dimensões especificadas pelo vetor 'offset'.
 * Retorna a cor da textura na posição indicada pelos valores de 'offset'.
 *
 * @param texture Imagem/textura da qual obter a cor.
 * @param offset Vetor contendo as dimensões [deslocamento, distância até o topo].
 * @return Cor da textura na posição indicada pelos valores de 'offset'.
 */
static int	get_texture_color(t_image texture, int offset[2])
{
	return (*(unsigned int *)(texture.i_add + (offset[1] * texture.size_line + offset[0] * (texture.bpp / 8))));
}

/**
 * @brief Obtém a cor da textura com base nas coordenadas e inversão especificadas.
 *
 * Esta função calcula as dimensões da parede na tela usando 'cal_wall_dimension'
 * e obtém a cor da textura na posição indicada pelas dimensões calculadas usando 'get_texture_color'.
 * Retorna a cor da textura na posição indicada pelas coordenadas e inversão.
 *
 * @param game Ponteiro para a estrutura principal do jogo.
 * @param texture Imagem/textura da qual obter a cor.
 * @param coord Vetor contendo as coordenadas [x, y] da tela.
 * @param invert Valor de inversão.
 * @return Cor da textura na posição indicada pelas coordenadas e inversão.
 */
int	get_texture(t_game *game, t_image texture, int coord[2], int invert)
{
	int	offset[2];

	cal_wall_dimension(game, coord, invert, offset);
	return (get_texture_color(texture, offset));
}
