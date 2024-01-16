/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verification.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:54:42 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/13 22:55:03 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
** Verifica se a quantidade correta de jogadores foi especificada e se está corretamente posicionada no mapa.
** Retorna 1 se as condições são atendidas, 0 caso contrário, exibindo uma mensagem de erro se necessário.
**
* @param input: Estrutura contendo informações de entrada.
* @param map: Mapa do jogo representado por uma matriz de inteiros.
** 
** Nota: Esta função utiliza a função ft_free_map_array.
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
** Verifica se todos os elementos do jogo estão corretos e válidos.
** Esta função verifica várias propriedades do jogo, como texturas, cores do chão e do teto, etc.
** Retorna 1 se todas as verificações passarem e 0 caso contrário.
** 
* @param line: linha do arquivo de configuração a ser verificada.
* @param input: estrutura contendo todas as configurações do jogo.
** 
** Nota: Esta função utiliza as funções has_texture e has_floor_ceiling.
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

static int	process_map_line(char *line_map, t_config **input)
{
	if ((*input)->width < ft_strlen(line_map))
		(*input)->width = ft_strlen(line_map);
	(*input)->height++;
	return (0);
}

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
