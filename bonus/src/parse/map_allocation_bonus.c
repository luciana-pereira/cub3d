/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_allocation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:27:06 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/13 20:31:13 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/**
 * @brief Aloca memória para a matriz do mapa com base na altura fornecida nas configurações.
 *
 * Esta função aloca dinamicamente memória para a matriz do mapa com base na altura fornecida nas configurações.
 * Retorna um ponteiro para a matriz alocada ou NULL se a altura for menor ou igual a zero.
 *
 * @param input Ponteiro para a estrutura de configuração do jogo.
 * @return Ponteiro para a matriz alocada ou NULL em caso de falha.
 */
static int **allocate_map_memory(t_config **input)
{
	int **map;

	map = NULL;
	if ((*input)->height > 0)
		map = (int **)malloc(sizeof(int *) * (*input)->height);
	return (map);
}

/**
 * @brief Aloca memória para uma linha da matriz do mapa.
 *
 * Esta função aloca dinamicamente memória para uma linha da matriz do mapa com base na largura fornecida
 * nas configurações. Retorna um ponteiro para a linha alocada ou NULL em caso de falha na alocação de memória.
 *
 * @param input Ponteiro para a estrutura de configuração do jogo.
 * @return Ponteiro para a linha alocada ou NULL em caso de falha.
 */
static int	*allocate_map_row(t_config **input)
{
	int	*row_ptr;

	row_ptr = (int *)malloc(sizeof(int) * (*input)->width);
	if (!row_ptr)
		return (NULL);
	return (row_ptr);
}

/**
 * @brief Aloca memória para obter o elemento e verifica se é válido.
 *
 * Esta função verifica se a coluna está dentro dos limites da string na lista encadeada. Com base nisso,
 * ela chama 'get_element' para obter o elemento da string ou um caractere de espaço, se necessário.
 * Se a obtenção do elemento falhar, a função libera a memória alocada para as linhas anteriores da matriz
 * e retorna -1, indicando um erro.
 *
 * @param input Ponteiro para a estrutura de configuração do jogo.
 * @param start Ponteiro para o início da lista encadeada contendo as informações do mapa.
 * @param row Índice da linha.
 * @param col Índice da coluna.
 * @param map Ponteiro para a matriz do mapa.
 * @return Valor do elemento ou -1 em caso de erro.
 */
static int	allocate_and_get_element(t_config **input, t_lst *start, size_t row, size_t col, int **map)
{
	int	element;

	if (col + 1 >= ft_strlen(start->content))
		element = get_element(' ', input, row, col);
	else
		element = get_element(start->content[col], input, row, col);
	if (element == -1)
	{
		free_2d_array(map, row + 1);
		return (-1);
	}
	return (element);
}

/**
 * @brief Popula uma linha específica da matriz do mapa com base nas informações fornecidas.
 *
 * Esta função aloca memória para uma linha da matriz usando 'allocate_map_row' e, em seguida, itera sobre
 * as colunas, chamando 'allocate_and_get_element' para preencher cada elemento da linha.
 * Se a alocação de memória falhar ou se houver um erro ao obter o elemento, a função libera a memória alocada
 * para a linha e retorna NULL.
 *
 * @param start Ponteiro para o início da lista encadeada contendo as informações do mapa.
 * @param input Ponteiro para a estrutura de configuração do jogo.
 * @param map Ponteiro para a matriz do mapa.
 * @param row Índice da linha a ser preenchida.
 * @return Ponteiro para a matriz do mapa se a operação for bem-sucedida, NULL em caso de falha.
 */
static int	**populate_map_row(t_lst *start, t_config **input, int **map, size_t row)
{
	size_t	col;

	map[row] = allocate_map_row(input);
	if (!map[row])
		return (NULL);
	col = -1;
	while (++col < (*input)->width)
	{
		map[row][col] = allocate_and_get_element(input, start, row, col, map);
		if (map[row][col] == -1)
			return (NULL);
	}
	return (map);
}

/**
 * @brief Popula as linhas da matriz do mapa com base nas informações fornecidas.
 *
 * Esta função popula as linhas da matriz do mapa com base nas informações fornecidas pela lista encadeada.
 * Itera sobre as linhas da matriz e chama a função 'populate_map_row' para preencher cada linha.
 * Se a operação falhar, libera a memória alocada para a matriz e retorna NULL.
 *
 * @param start Ponteiro para o início da lista encadeada contendo as informações do mapa.
 * @param input Ponteiro para a estrutura de configuração do jogo.
 * @param map Ponteiro para a matriz do mapa.
 * @return Ponteiro para a matriz do mapa se a operação for bem-sucedida, NULL em caso de falha.
 */
static int	**populate_map(t_lst *start, t_config **input, int **map)
{
	size_t	row;

	row = 0;
	while (row < (*input)->height)
	{
		map = populate_map_row(start, input, map, row);
		if (!map)
			return (NULL);
		start = start->next;
		row++;
	}
	return (map);
}

/**
 * @brief Cria e popula a matriz do mapa com base na lista encadeada e nas configurações fornecidas.
 *
 * Esta função aloca a memória para a matriz do mapa usando a função 'allocate_map_memory'. Em seguida, ela popula a
 * matriz usando a função 'populate_map' com base na lista encadeada e nas configurações fornecidas. Verifica se a
 * operação foi bem-sucedida e se os jogadores no mapa são válidos usando a função 'verify_players'. Se houver falha
 * em qualquer etapa, libera a memória alocada para a matriz e retorna NULL.
 *
 * @param start Ponteiro para o início da lista encadeada contendo as informações do mapa.
 * @param input Ponteiro para a estrutura de configuração do jogo.
 * @return Ponteiro para a matriz do mapa se a criação for bem-sucedida, NULL em caso de falha.
 */
int **create_map(t_lst *start, t_config **input)
{
	int	**map;

	map = allocate_map_memory(input);
	if (!map)
		return NULL;
	map = populate_map(start, input, map);
	if (!map || !verify_players(*input, map))
	{
		free_2d_array(map, (*input)->height);
		return (NULL);
	}
	return (map);
}
