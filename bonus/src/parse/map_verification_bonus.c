/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verification_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:54:42 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/13 22:55:03 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/**
 * @brief Verifica se as configurações do jogador são válidas.
 *
 * Esta função verifica se as configurações do jogador são válidas com base no número de jogadores
 * e na largura do mapa. Se a largura for zero ou o número de jogadores for maior que 1 ou igual a zero,
 * imprime uma mensagem de erro, libera a memória alocada para o mapa e retorna 0. Retorna 1 se as configurações do jogador são válidas.
 *
 * @param input Ponteiro para a estrutura de configuração do jogo.
 * @param map Matriz contendo o mapa.
 * @return 1 se as configurações do jogador são válidas, 0 caso contrário.
 */
int	verify_players(t_config *input, int **map)
{
	if (!input->width)
		return (0);
	if (input->player > 1 || input->player == 0)
	{
		print_error(INVALID_PLAYER);
		free_2d_array(map, input->height);
		return (0);
	}
	return (1);
}

/**
 * @brief Verifica se todos os elementos da linha são válidos.
 *
 * Esta função verifica se a linha contém uma chave de configuração válida usando 'verify_line'.
 * Em seguida, verifica e processa as texturas, cores de chão e teto usando 'has_texture' e 'has_floor_ceiling'.
 * Retorna 0 se algum elemento não for válido, exibindo uma mensagem de erro. Retorna 1 se todos os elementos forem válidos.
 *
 * @param line String contendo a linha a ser verificada.
 * @param input Ponteiro para a estrutura de configuração do jogo.
 * @return 0 se algum elemento não for válido, 1 se todos os elementos forem válidos.
 */
int	verify_all_elements(char *line, t_config *input)
{
	if (line[0] && !verify_line(line))
	{
		print_error(INVALID_CHARAC);
		return (0);
	}
	if (has_texture(line, input, "NO ", &input->tex.north) ||
		has_texture(line, input, "SO ", &input->tex.south) ||
		has_texture(line, input, "WE ", &input->tex.west) ||
		has_texture(line, input, "EA ", &input->tex.east) ||
		has_floor_ceiling(line, &input->floor_color, "F ", &input->floor) ||
		has_floor_ceiling(line, &input->ceiling_color, "C ", &input->ceiling))
		return (0);
	return (1);
}

/**
 * @brief Verifica se um bloco de mapa é válido.
 *
 * Esta função verifica se um bloco de mapa é válido com base na linha do mapa e na flag inside_map.
 * Retorna 1 se o bloco for válido, 0 se estiver vazio e dentro do mapa, e -1 se estiver fora do mapa e não vazio.
 *
 * @param line_map String contendo a linha do mapa.
 * @param inside_map Flag indicando se está dentro ou fora do mapa.
 * @return 1 se o bloco for válido, 0 se estiver vazio e dentro do mapa, -1 se estiver fora do mapa e não vazio.
 */
static int	is_valid_map_block(char *line_map, int inside_map)
{
	if (line_map == NULL || line_map[0] == 0)
	{
		if (inside_map == 1)
			return (0);
	}
	else if (inside_map == 0)
	{
		free(line_map);
		return (-1);
	}
	return (1);
}

/**
 * @brief Processa uma linha do mapa e atualiza as configurações do jogo.
 *
 * Esta função processa uma linha do mapa, atualizando a largura e altura do mapa nas configurações do jogo.
 * Retorna 0 após processar a linha.
 *
 * @param line_map String contendo a linha do mapa.
 * @param input Ponteiro para a estrutura de configuração do jogo.
 * @return 0 após processar a linha.
 */
static int	process_map_line(char *line_map, t_config **input)
{
	if ((*input)->width < ft_strlen(line_map))
		(*input)->width = ft_strlen(line_map);
	(*input)->height++;
	return (0);
}

/**
 * @brief Verifica se o mapa é válido.
 *
 * Esta função verifica se o mapa é válido com base nas linhas do mapa, nas configurações do jogo e na flag inside_map.
 * Itera sobre as linhas do mapa, remove espaços em branco, verifica a validade do bloco de mapa usando 'is_valid_map_block',
 * e processa a linha do mapa usando 'process_map_line' se for válido. Retorna -1 se encontrar um bloco inválido fora do mapa,
 * 0 se todas as linhas forem processadas corretamente.
 *
 * @param map Ponteiro para a lista de linhas do mapa.
 * @param input Ponteiro para a estrutura de configuração do jogo.
 * @param inside_map Flag indicando se está dentro ou fora do mapa.
 * @return -1 se encontrar um bloco inválido fora do mapa, 0 se todas as linhas forem processadas corretamente.
 */
int	verify_map(t_lst *map, t_config **input, int inside_map)
{
	char	*line_map;
	int		result;

	while (map && map->next)
	{
		line_map = remove_whitespaces(map->content);
		result = is_valid_map_block(line_map, inside_map);
		if (result == -1)
			return (-1);
		else if (result == 1)
			process_map_line(line_map, input);
		free(line_map);
		map = map->next;
	}
	return (0);
}
