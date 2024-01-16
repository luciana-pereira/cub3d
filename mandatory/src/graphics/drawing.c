/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:16:21 by luizedua          #+#    #+#             */
/*   Updated: 2024/01/14 02:00:47 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * @brief Inicializa a biblioteca gráfica e cria uma imagem variável no contexto do jogo.
 *
 * Esta função tem como objetivo inicializar a biblioteca gráfica definida pelo
 * ponteiro `addr` e criar uma imagem variável no contexto do jogo. A imagem é
 * configurada com largura e altura especificadas por WIN_W e WIN_H, respectivamente.
 * Os detalhes da imagem, como o ponteiro para os dados, a quantidade de bits por pixel
 * (bpp), o comprimento da linha (line_len) e a ordem dos bytes (endian), são
 * armazenados na estrutura `t_image`.
 *
 * @param game Ponteiro para a estrutura principal do jogo.
 * @return Uma estrutura `t_image` contendo as informações da imagem criada.
 */
void	paint_img(t_image *image, int x, int y, int color)
{
	char	*dest;

	if (x > WIN_W || y > WIN_H || x < 0 || y < 0)
		return ;
	dest = (char *)image->data + (y * image->size_line + x * (image->bpp / 8));
	*(unsigned int *)dest = color;
}

/**
 * @brief Imprime o mapa do jogo no console.
 *
 * Esta função recebe um ponteiro para a estrutura `t_map` e uma matriz de inteiros `map_matrix`
 * representando o mapa do jogo. Ela percorre a matriz e imprime no console os caracteres
 * correspondentes aos códigos presentes em cada posição do mapa. Os caracteres são obtidos
 * somando o valor na posição da matriz `map_matrix` com o caractere '0'.
 *
 * @param map Ponteiro para a estrutura principal do jogo, contendo informações sobre as
 *            dimensões do mapa.
 * @param map_matrix Matriz de inteiros representando o mapa a ser impresso.
 */
void print_map(t_map *map, int **map_matrix)
{
	int		row;
	int		col;
	char	code_to_char;

	row = 0;
	while (row < (int)map->y / 64)
	{
		col = 0;
		while (col < (int)map->x / 64)
		{
			code_to_char = map_matrix[row][col] + '0';
			write(1, &code_to_char, 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}
