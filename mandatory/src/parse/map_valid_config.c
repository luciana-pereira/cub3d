/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_config.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/13 23:19:39 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	handle_valid_element(char element, t_config **input, int x, int y)
{
	if (element != '0')
	{
		(*input)->px = x;
		(*input)->py = y;
		(*input)->player++;
	}
	if (element == SOUTH)
		(*input)->player_dir = DIR_SOUTH;
	else if (element == WEST)
		(*input)->player_dir = DIR_WEST;
	else if (element == NORTH)
		(*input)->player_dir = DIR_NORTH;
	else if (element == EAST)
		(*input)->player_dir = DIR_EAST;
	return (0);
}

int	get_element(char element, t_config **input, int x, int y)
{
	if (element == '1')
		return (1);
	if (element == SOUTH || element == NORTH ||
		element == WEST || element == EAST || element == '0')
		return handle_valid_element(element, input, x, y);
	if (element == ' ')
		return (EMPTY);
	print_error(INVALID_CHARAC);
	return (-1);
}

/**
** Verifica se a string de entrada corresponde a uma das opções válidas para as configurações do jogo.
** Retorna 1 se a string é uma opção válida, 0 caso contrário.
** 
* @param line: string a ser verificada.
** 
** Nota: Esta função é utilizada para verificar se a linha de entrada contém configurações válidas.
*/
int	verify_line(char *line)
{
	if (!ft_strncmp(line, "NO", 2) ||
		!ft_strncmp(line, "SO", 2) ||
		!ft_strncmp(line, "WE", 2) ||
		!ft_strncmp(line, "EA", 2) ||
		!ft_strncmp(line, "F ", 2) ||
		!ft_strncmp(line, "C ", 2))
	{
		return (1);
	}
	return (0);
}

/**
** Verifica se a posição (x, y) no mapa contém um elemento específico.
**
* @param map: Estrutura contendo informações do mapa.
* @param x: Coordenada x na qual verificar o mapa.
* @param y: Coordenada y na qual verificar o mapa.
* @param flag: Valor a ser verificado na posição do mapa (1 para parede, 0 para chão).
* @return 1 se a posição contém o valor especificado, 0 caso contrário.
*/
int	verify_coords_elements(t_map *map, float x, float y, int flag)
{
	if (x < 0 || x > (float)map->x || y < 0 || y > (float)map->y)
		return (1);
	if (map->map[(int)floor(y / 64)][(int)floor(x / 64)] == flag)
		return (1);
	return (0);
}
