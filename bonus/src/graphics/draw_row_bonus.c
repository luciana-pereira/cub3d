/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_row_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/18 06:40:47 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void initialize_decision(int *difference, int is_horizontal, int *decision)
{
    if (is_horizontal == 1)
        *decision = (2 * difference[1]) - difference[0];
    else
        *decision = (2 * difference[0]) - difference[1];
}

static void	update_decision(t_image *image, t_coords *start, int *diff, int *decision, int color, int is_horizontal)
{
	if (is_horizontal == 1)
		start->x = start->x + diff[2];
	else
		start->y = start->y + diff[3];
	if (*decision <= 0)
		*decision += (2 * diff[is_horizontal % 2]);
	else
	{
		*decision += 2 * (diff[is_horizontal % 2] - diff[is_horizontal % 2]);
		if (is_horizontal == 1)
		{
			*decision += 2 * (diff[is_horizontal % 2] - diff[0]);
			start->y = start->y + diff[3];
		}
		else
		{
			*decision += 2 * (diff[is_horizontal % 2] - diff[1]);
			start->x = start->x + diff[2];
		}
	}
		paint_img(image, start->x, start->y, color);
}

/**
 * @brief Desenha uma linha na imagem entre os pontos A (inicial) e B (final) utilizando o algoritmo Bresenham.
 *
 * Esta função desenha uma linha na imagem entre os pontos 'start' e 'end'
 * utilizando o algoritmo de Bresenham. A cor da linha é especificada por
 * 'color'. A função recebe um ponteiro para a estrutura da imagem, as
 * coordenadas iniciais e finais, e a cor da linha.
 *
 * @param image Ponteiro para a estrutura da imagem.
 * @param start Coordenada inicial.
 * @param end Coordenada final.
 * @param color Cor da linha.
 * @param is_horizontal Indica se a linha deve ser desenhada horizontalmente (1) ou verticalmente (2).
 */
void	draw_row_img(t_image *image, t_coords start, t_coords end, int color, int is_horizontal)
{
	int	*difference;
	int	decision;

	paint_img(image, start.x, start.y, color);
	difference = calculate_diff(start, end);
	initialize_decision(difference, is_horizontal, &decision);
	while ((is_horizontal == 1 && start.x != end.x) 
		|| (is_horizontal == 2 && start.y != end.y))
		update_decision(image, &start, difference, &decision, color, is_horizontal);
	paint_img(image, end.x, end.y, color);
	free(difference);
}

/**
 * @brief Desenha uma linha na imagem entre os pontos A(inicial) e B(final) utilizando o algoritmo Bresenham.
 *
 * Esta função desenha uma linha na imagem entre os pontos 'start' e 'end'
 * utilizando o algoritmo de Bresenham. A cor da linha é especificada por
 * 'color'.
 *
 * @param image Ponteiro para a estrutura da imagem.
 * @param start Coordenada inicial.
 * @param end Coordenada final.
 * @param color Cor da linha.
 */
void	draw_row(t_image *image, t_coords start, t_coords end, int color)
{
	int	diff_x;
	int	diff_y;

	diff_x = start.x - end.x;
	diff_y = start.y - end.y;
	if (end.x > start.x)
		diff_x = end.x - start.x;
	if (end.y > start.y)
		diff_y = end.y - start.y;
	if (diff_x >= diff_y)
		draw_row_img(image, start, end, color, 1);
	else
		draw_row_img(image, start, end, color, 2);
}
