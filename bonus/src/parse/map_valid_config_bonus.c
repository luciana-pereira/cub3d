/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_config_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/13 23:19:39 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/**
 * @brief Processa elementos válidos do mapa e atualiza as configurações do jogador.
 *
 * Esta função é chamada quando o elemento é '0', SOUTH, NORTH, WEST ou EAST.
 * Se o elemento não for '0', atualiza as configurações do jogador (posição e direção) no contexto do mapa.
 * Retorna 0 após processar o elemento.
 *
 * @param element Elemento a ser processado.
 * @param input Ponteiro para a estrutura de configuração do jogo.
 * @param x Coordenada x.
 * @param y Coordenada y.
 * @return 0 após processar o elemento.
 */
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

/**
 * @brief Obtém o valor numérico correspondente a um elemento no mapa.
 *
 * Esta função mapeia o caractere fornecido para o valor numérico correspondente no contexto do mapa.
 * Se o caractere for '1', retorna 1. Se for '0', SOUTH, NORTH, WEST, EAST, chama 'handle_valid_element'
 * para processar o elemento e retornar o valor correspondente. Se for ' ', retorna EMPTY.
 * Se o caractere não corresponder a nenhum elemento válido, imprime uma mensagem de erro e retorna -1.
 *
 * @param element Caractere a ser convertido.
 * @param input Ponteiro para a estrutura de configuração do jogo.
 * @param x Coordenada x.
 * @param y Coordenada y.
 * @return Valor numérico correspondente ao elemento ou -1 em caso de erro.
 */
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
 * @brief Verifica se a linha fornecida contém uma chave de configuração válida.
 *
 * Esta função verifica se a linha inicia com uma das chaves de configuração válidas:
 * "NO", "SO", "WE", "EA", "F ", "C ". Retorna 1 se a linha contiver uma chave válida, 0 caso contrário.
 *
 * @param line String contendo a linha a ser verificada.
 * @return 1 se a linha contiver uma chave válida, 0 caso contrário.
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
 * @brief Verifica se as coordenadas especificadas são válidas no mapa.
 *
 * Esta função verifica se as coordenadas (x, y) estão dentro dos limites do mapa e se a posição no mapa
 * correspondente contém o valor especificado pela flag. Retorna 1 se as coordenadas não são válidas, 0 caso contrário.
 *
 * @param map Ponteiro para a estrutura do mapa.
 * @param x Coordenada x.
 * @param y Coordenada y.
 * @param flag Valor a ser verificado na posição do mapa.
 * @return 1 se as coordenadas não são válidas, 0 caso contrário.
 */
int	verify_coords_elements(t_map *map, float x, float y, int flag)
{
	if (x < 0 || x > (float)map->x || y < 0 || y > (float)map->y)
		return (1);
	if (map->map[(int)floor(y / 64)][(int)floor(x / 64)] == flag)
		return (1);
	return (0);
}
