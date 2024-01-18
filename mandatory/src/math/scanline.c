/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 22:39:11 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/13 22:39:28 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void scanline_fill(int **duplicate, int x, int y, t_map *map);

/**
 * @brief Verifica se uma célula no mapa já foi visitada.
 *
 * Esta função verifica se uma célula no mapa já foi visitada com base no valor da célula.
 * Retorna true se a célula foi visitada (valor 1, 2 ou 3), caso contrário, retorna false.
 *
 * @param cell_value Valor da célula no mapa.
 * @return true se a célula foi visitada, false caso contrário.
 */
static bool	is_visited(int cell_value)
{
	return (cell_value == 1 || cell_value == 3 || cell_value == 2);
}

/**
 * @brief Preenche uma linha acima da área atual no mapa.
 *
 * Esta função preenche uma linha acima da área atual, percorrendo os pixels da borda esquerda até a borda direita.
 * Se o pixel não foi visitado, chama a função 'scanline_fill' para preencher a área contígua na linha acima.
 *
 * @param duplicate Matriz de marcação indicando áreas já visitadas.
 * @param left Coordenada x da borda esquerda.
 * @param right Coordenada x da borda direita.
 * @param y Coordenada y da linha acima.
 */
static void	fill_line_above(int **duplicate, int left, int right, int y)
{
	int 	index;
	t_map	map;

	index = left + 1;
	while (index < right)
	{
		if (!is_visited(duplicate[y - 1][index]))
			scanline_fill(duplicate, index, y - 1, &map);
		index++;
	}
}

/**
 * @brief Preenche uma linha abaixo da área atual no mapa.
 *
 * Esta função preenche uma linha abaixo da área atual, percorrendo os pixels da borda esquerda até a borda direita.
 * Se o pixel não foi visitado, chama a função 'scanline_fill' para preencher a área contígua na linha abaixo.
 *
 * @param duplicate Matriz de marcação indicando áreas já visitadas.
 * @param left Coordenada x da borda esquerda.
 * @param right Coordenada x da borda direita.
 * @param y Coordenada y da linha abaixo.
 */
static void	fill_line_below(int **duplicate, int left, int right, int y)
{
	int		count;
	t_map	map;

	count = left + 1;
	while (count < right)
	{
		if (!is_visited(duplicate[y + 1][count]))
			scanline_fill(duplicate, count, y + 1, &map);
		count++;
	}
}

/**
 * @brief Preenche uma área contígua no mapa usando o algoritmo Scanline Fill.
 *
 * Esta função encontra a borda esquerda e direita da área a ser preenchida, marca os pixels como visitados e,
 * em seguida, chama funções auxiliares para preencher as linhas acima e abaixo da área atual.
 *
 * @param duplicate Matriz de marcação indicando áreas já visitadas.
 * @param x Coordenada x da posição no mapa.
 * @param y Coordenada y da posição no mapa.
 * @param map Ponteiro para a estrutura do mapa.
 */
void	scanline_fill(int **duplicate, int x, int y, t_map *map)
{
	int	left;
	int	right;

	// Encontrar a borda esquerda
	left = x;
	while (left >= 0 && !is_visited(duplicate[y][left]) 
		&& !(x == 0 || y == 0 || x == (map->x / 64) - 1
		|| y == (map->y / 64) - 1))
	{
		duplicate[y][left] = 3;
		left--;
	}
	// Encontrar a borda direita
	right = x + 1;
	while (right < (map->x / 64) && !is_visited(duplicate[y][right]) 
		&& !(x == 0 || y == 0 || x == (map->x / 64) - 1
		|| y == (map->y / 64) - 1))
	{
		duplicate[y][right] = 3;
		right++;
	}
	// Preencher a linha acima
	if (y > 0)
		fill_line_above(duplicate, left, right, y);
	// Preencher a linha abaixo
	if (y < (map->y / 64) - 1)
		fill_line_below(duplicate, left, right, y);
}

/**
 * @brief Preenche uma área contígua no mapa usando o algoritmo Scanline Flood Fill.
 *
 * Esta função verifica se a posição (x, y) está dentro dos limites do mapa, se não foi visitada e, se atender a essas
 * condições, chama a função auxiliar 'scanline_fill' para preencher a área contígua.
 *
 * @param duplicate Matriz de marcação indicando áreas já visitadas.
 * @param x Coordenada x da posição no mapa.
 * @param y Coordenada y da posição no mapa.
 * @param map Ponteiro para a estrutura do mapa.
 */
// Função principal para preenchimento de scanline
void	scanline_flood_fill(int **duplicate, int x, int y, t_map *map)
{
	if (y >= 0 && x >= 0 && y < (map->y / 64) && x < (map->x / 64) 
		&& !is_visited(duplicate[y][x]))
		scanline_fill(duplicate, x, y, map);
}
