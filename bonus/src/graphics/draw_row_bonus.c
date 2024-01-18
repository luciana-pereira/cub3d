/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_row_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/18 01:16:12 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/**
** Aloca e retorna um array de inteiros contendo as diferenças das coordenadas x e y.
** As diferenças indicam a direção e a distância entre os pontos a e b.
**
* @param a: Coordenada a.
* @param b: Coordenada b.
* @return Um array de inteiros [dx, dy, sign_x, sign_y], onde dx e dy são as distâncias em x e y,
**         e sign_x e sign_y indicam a direção (1 para positivo, -1 para negativo).
** Nota: A função utiliza alocação dinâmica de memória para o array de inteiros.
*/
// int	*calculate_diff(t_pos a, t_pos b)
// {
// 	int	*difference;

// 	difference = malloc(4 * sizeof(int));
// 	if (b.x > a.x)
// 	{
// 		difference[2] = 1;
// 		difference[0] = b.x - a.x;
// 	}
// 	else
// 	{
// 		difference[2] = -1;
// 		difference[0] = a.x - b.x;
// 	}
// 	if (b.y > a.y)
// 	{
// 		difference[3] = 1;
// 		difference[1] = b.y - a.y;
// 	}
// 	else
// 	{
// 		difference[3] = -1;
// 		difference[1] = a.y - b.y;
// 	}
// 	return (difference);
// }

// void	draw_line_util_1(t_image *image, t_pos a, t_pos b, int color)
// {
// 	int	*delta;
// 	int	decision;

// 	paint_img(image, a.x, a.y, color);
// 	delta = get_delta(a, b);
// 	decision = (2 * delta[1]) - delta[0];
// 	while (a.x != b.x)
// 	{
// 		a.x = a.x + delta[2];
// 		if (decision <= 0)
// 		{
// 			decision += (2 * delta[1]);
// 			paint_img(image, a.x, a.y, color);
// 		}
// 		else
// 		{
// 			decision += 2 * (delta[1] - delta[0]);
// 			a.y = a.y + delta[3];
// 			paint_img(image, a.x, a.y, color);
// 		}
// 	}
// 	paint_img(image, b.x, b.y, color);
// 	free(delta);
// }

// void	draw_line_util_2(t_image *image, t_pos a, t_pos b, int color)
// {
// 	int	*delta;
// 	int	decision;

// 	paint_img(image, a.x, a.y, color);
// 	delta = get_delta(a, b);
// 	decision = (2 * delta[0]) - delta[1];
// 	while (a.y != b.y)
// 	{
// 		a.y = a.y + delta[3];
// 		if (decision <= 0)
// 		{
// 			decision += (2 * delta[0]);
// 			paint_img(image, a.x, a.y, color);
// 		}
// 		else
// 		{
// 			decision += 2 * (delta[0] - delta[1]);
// 			a.x = a.x + delta[2];
// 			paint_img(image, a.x, a.y, color);
// 		}
// 	}
// 	paint_img(image, b.x, b.y, color);
// 	free(delta);
// }

/**
** Desenha uma linha na imagem entre os pontos A e B utilizando o algoritmo Bresenham.
**
* @param image: Estrutura de imagem onde a linha será desenhada.
* @param a: Coordenada inicial da linha (ponto A).
* @param b: Coordenada final da linha (ponto B).
* @param color: Cor da linha.
*/
// void	draw_line(t_image *image, t_pos a, t_pos b, int color)
// {
// 	int	delta_x;
// 	int	delta_y;

// 	delta_x = a.x - b.x;
// 	delta_y = a.y - b.y;
// 	if (b.x > a.x)
// 		delta_x = b.x - a.x;
// 	if (b.y > a.y)
// 		delta_y = b.y - a.y;
// 	if (delta_x >= delta_y)
// 		draw_line_util_1(image, a, b, color);
// 	else
// 		draw_line_util_2(image, a, b, color);
// }
/**
 * @brief Desenha uma linha horizontal ou vertical do algoritmo de Bresenham.
 *
 * Esta função desenha uma linha horizontal ou vertical utilizando o algoritmo de Bresenham.
 * A cor da linha é especificada por 'color'.
 *
 * @param image Ponteiro para a estrutura da imagem.
 * @param start Coordenada inicial.
 * @param end Coordenada final.
 * @param color Cor da linha.
 * @param is_horizontal Flag indicando se a linha é horizontal (1) ou vertical (2).
 */
static void	draw_line_util(t_image *image, t_coords start, t_coords end, int color, int is_horizontal)
{
	int	*difference;
	int	decision;

	difference = calculate_diff(start, end);
	paint_img(image, start.x, start.y, color);
	if (is_horizontal == 1)
		decision = (2 * difference[1]) - difference[0];
	else
		decision = (2 * difference[0]) - difference[1];
	while ((is_horizontal == 1 && start.x != end.x)
		|| (is_horizontal == 2 && start.y != end.y))
	{
		if (is_horizontal == 1)
			start.x += difference[2];
		else
			start.y += difference[3];
		if (decision <= 0)
		{
			decision += (2 * difference[is_horizontal - 1]);
			paint_img(image, start.x, start.y, color);
		}
		else
		{
			decision += 2 * (difference[is_horizontal - 1] - difference[is_horizontal % 2]);
			if (is_horizontal == 1)
				start.y += difference[3];
			else
				start.x += difference[2];
			paint_img(image, start.x, start.y, color);
		}
	}
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
		diff_x = (end.x - start.x);
	if (end.y > start.y)
		diff_y = (end.y - start.y);
	if (diff_x >= diff_y)
		draw_line_util(image, start, end, color, 1);
	else
		draw_line_util(image, start, end, color, 2);
}
