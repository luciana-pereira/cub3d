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

// Função para verificar se a célula já foi visitada
static bool	is_visited(int cell_value)
{
	return (cell_value == 1 || cell_value == 3 || cell_value == 2);
}

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

// Função principal para preenchimento de scanline
void	scanline_flood_fill(int **duplicate, int x, int y, t_map *map)
{
	if (y >= 0 && x >= 0 && y < (map->y / 64) && x < (map->x / 64) 
		&& !is_visited(duplicate[y][x]))
		scanline_fill(duplicate, x, y, map);
}
