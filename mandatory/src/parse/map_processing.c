/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:33:11 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/13 23:41:30 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * @brief Lê as linhas do mapa do arquivo e armazena em uma lista encadeada.
 *
 * Esta função lê as linhas do mapa do arquivo usando 'get_next_line' e armazena cada linha em um nó da lista encadeada.
 * Retorna um ponteiro para o início da lista encadeada, onde cada nó contém uma linha do mapa.
 *
 * @param fd Descritor de arquivo do mapa.
 * @param node Ponteiro para a lista encadeada que armazenará as linhas do mapa.
 * @return Ponteiro para o início da lista encadeada contendo as linhas do mapa.
 */
static t_lst	*read_map_lines(int fd, t_lst *node)
{
	char	*line;
	t_lst	*start;
	t_lst	*new;

	start = node;
	line = get_next_line(fd);
	while (line)
	{
		node->content = line;
		new = (t_lst *)malloc(sizeof(t_lst));
		new->next = NULL;
		new->content = NULL;
		node->next = new;
		node = node->next;
		line = get_next_line(fd);
	}
	close(fd);
	return (start);
}

/**
 * @brief Processa os dados do mapa e gera a matriz do mapa.
 *
 * Esta função remove linhas vazias da lista encadeada usando 'remove_empty' e verifica a validade do mapa
 * usando 'verify_map'. Se a verificação falhar, a função imprime uma mensagem de erro e retorna NULL.
 * Em seguida, chama 'create_map' para gerar a matriz do mapa. Se a geração falhar, a função libera a memória
 * alocada para as configurações e as linhas do mapa, e retorna NULL. Caso contrário, retorna a matriz do mapa gerada.
 *
 * @param start Ponteiro para o início da lista encadeada contendo as linhas do mapa.
 * @param input Ponteiro para a estrutura de configuração do jogo.
 * @return Ponteiro para a matriz do mapa gerada ou NULL em caso de erro.
 */
static int	**process_map_data(t_lst *start, t_config **input)
{
	int	**map;

	start = remove_empty(start);
	if (verify_map(start, input, 1) == -1)
		print_error(INVALID_MAP);
	map = create_map(start, input);
	if (map == NULL)
		free_input((*input));
	free_map_lines(start);
	return (map);
}

/**
 * @brief Lê e processa as linhas do mapa.
 *
 * Esta função chama 'read_map_lines' para ler as linhas do mapa do arquivo e armazená-las em uma lista encadeada.
 * Em seguida, chama 'process_map_data' para processar as informações do mapa e gerar a matriz do mapa.
 * Retorna a matriz do mapa gerada.
 *
 * @param fd Descritor de arquivo do mapa.
 * @param input Ponteiro para a estrutura de configuração do jogo.
 * @param node Ponteiro para a lista encadeada que armazenará temporariamente as linhas do mapa.
 * @return Ponteiro para a matriz do mapa gerada.
 */
int	**read_map(int fd, t_config **input, t_lst *node)
{
	t_lst	*start;
	int		**map;

	start = read_map_lines(fd, node);
	map = process_map_data(start, input);
	return (map);
}
