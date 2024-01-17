/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/17 16:23:18 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * @brief Calcula a posição superior na tela.
 *
 * Esta função é chamada pela função principal calculate_position quando o controle indica que
 * a posição deve ser ajustada para a parte superior da tela. Ela realiza o cálculo e verifica
 * se a posição resultante é menor que zero, ajustando-a para zero nesse caso.
 *
 * @param wall_height Altura da parede calculada.
 * @return Posição superior ajustada.
 */
static int	calculate_upper_position(int wall_height)
{
	int	vertical_posit_top;

	vertical_posit_top = (WIN_H / 2) - wall_height;
	if (vertical_posit_top < 0)
		vertical_posit_top = 0;
	return (vertical_posit_top);
}

/**
 * @brief Calcula a posição inferior na tela.
 *
 * Esta função é chamada pela função principal calculate_position quando o controle indica que
 * a posição deve ser ajustada para a parte inferior da tela. Ela realiza o cálculo e verifica
 * se a posição resultante é maior que WIN_H, ajustando-a para WIN_H nesse caso.
 *
 * @param wall_height Altura da parede calculada.
 * @return Posição inferior ajustada.
 */
static int	calculate_lower_position(int wall_height)
{
	int	start_position;

	start_position = (WIN_H / 2) + wall_height;
	if (start_position > WIN_H)
		start_position = WIN_H;
	return (start_position);
}

/**
 * @brief Calcula a posição vertical do ponto de projeção na tela.
 *
 * Esta função calcula a posição vertical do ponto de projeção na tela com base nas informações
 * do jogo, como a distância do raio até a parede (fdist), a largura da parede no plano (plane),
 * a altura da janela (WIN_H), e um controle adicional (control) que determina se a posição deve
 * ser ajustada para a parte superior ou inferior da tela.
 *
 * @param game Ponteiro para a estrutura principal do jogo.
 * @param col Índice da coluna atual.
 * @param control Flag de controle para ajustar a posição para a parte superior ou inferior da tela.
 * @return Posição vertical calculada.
 */
int calculate_position(t_game *game, int col, int control)
{
    int wall_height;

	wall_height = floor((64 / game->rays[col].fdist) * game->map->plane) / 2;
    if (control)
        return (calculate_upper_position(wall_height));
    else
        return (calculate_lower_position(wall_height));
}

/**
** Calcula o deslocamento horizontal na textura com base na informação do raio.
** Retorna o valor do deslocamento.
** 
** @param ray: estrutura contendo informações sobre o raio lançado.
** @return: deslocamento horizontal na textura.
** 
** Nota: Esta função é utilizada para determinar o deslocamento horizontal na textura
**       com base na informação do raio, levando em consideração se o raio atingiu
**       uma parede vertical ou horizontal.
*/
int	calc_horizontal_disp(t_rays ray)
{
	if (ray.is_hit)
		return ((int)ray.hit_y % 64);
	else
		return ((int)ray.hit_x % 64);
}
