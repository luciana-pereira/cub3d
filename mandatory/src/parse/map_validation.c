/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/13 22:44:09 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * @brief Verifica se a cópia do mapa é válida.
 *
 * Esta função percorre a cópia do mapa e verifica se os valores nas posições são válidos.
 * Retorna 1 se a cópia do mapa for válida, 0 caso contrário.
 *
 * @param map Ponteiro para a estrutura do mapa.
 * @param duplicate Matriz contendo a cópia do mapa.
 * @return 1 se a cópia do mapa for válida, 0 caso contrário.
 */
static int	is_valid_duplicate(t_map *map, int **duplicate)
{
	int	x;
	int	y;
	int	pos;

	y = 0;
	while (y < map->y / 64)
	{
		x = 0;
		while (x < map->x / 64)
		{
			pos = duplicate[y][x];
			if (!((pos == 1 || pos == 0 || pos == 9) ||
				(pos == 5 || pos == 6 || pos == 7 || pos == 8) ||
				(pos == 3)))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

/**
 * @brief Verifica se o caminho no mapa é válido.
 *
 * Esta função verifica se o caminho no mapa é válido usando a técnica de preenchimento de varredura de linha.
 * Cria uma cópia do mapa usando 'copy_map', realiza o preenchimento de varredura de linha com 'scanline_flood_fill'
 * e verifica se a cópia é válida usando 'is_valid_duplicate'. Libera a memória alocada para a cópia do mapa
 * e retorna 0 se o caminho for inválido, exibindo uma mensagem de erro. Retorna 1 se o caminho for válido.
 *
 * @param map Ponteiro para a estrutura do mapa.
 * @param x Coordenada x.
 * @param y Coordenada y.
 * @return 0 se o caminho for inválido, 1 se for válido.
 */
int	is_valid_map_path(t_map *map, int x, int y)
{
	int	**duplicate;

	if (!map->map)
		return (0);
	duplicate = copy_map(map);
	scanline_flood_fill(duplicate, x, y, map);
	if (!is_valid_duplicate(map, duplicate))
	{
		free_2d_array(duplicate, map->y / 64);
		return (print_error(INVALID_PATH));
	}
	free_2d_array(duplicate, map->y / 64);
	return (0);
}
