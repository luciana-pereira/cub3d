/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 23:48:17 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/18 02:18:49 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/**
 * @brief Desenha uma linha horizontal do círculo na imagem.
 *
 * Esta função desenha uma linha horizontal do círculo na imagem, pintando os
 * pixels dentro do círculo com a cor vermelha.
 *
 * @param img Ponteiro para a estrutura da imagem.
 * @param x Coordenada x do início da linha.
 * @param y Coordenada y do início da linha.
 * @param center_x Coordenada x do centro do círculo.
 * @param center_y Coordenada y do centro do círculo.
 * @param radius Raio do círculo.
 */
static void	draw_circle_row(t_image *img, int x, int y, int center_x, int center_y, int radius)
{
	int	pos_x;
	int	pos_y;

	pos_x = x - center_x;
	pos_y = y - center_y;
	while (y <= center_y + radius)
	{
		if (pos_x * pos_x + pos_y * pos_y < radius * radius)
			paint_img(img, x, y, COLOR_RED);
		y++;
	}
}

/**
 * @brief Desenha um círculo na imagem com o centro especificado.
 *
 * Esta função desenha um círculo na imagem com o centro especificado pelas
 * coordenadas (xc, yc) e raio 'r'. O círculo é desenhado pintando os pixels
 * dentro do círculo com a cor vermelha.
 *
 * @param image Ponteiro para a estrutura da imagem.
 * @param xc Coordenada x do centro do círculo.
 * @param yc Coordenada y do centro do círculo.
 * @param radius Raio do círculo.
 */
void	draw_circle(t_image *image, int center_x, int center_y, int radius)
{
	int	x;
	int	y;

	x = center_x - radius;
	paint_img(image, center_x, center_y, COLOR_RED);
	while (x <= center_x + radius)
	{
		y = center_y - radius;
		draw_circle_row(image, x, y, center_x, center_y, radius);
		x++;
	}
}
