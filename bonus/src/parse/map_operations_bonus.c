/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/13 22:37:20 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/**
 * @brief Duplica o mapa fornecido, retornando uma cópia do mesmo.
 * Esta função aloca memória para o novo mapa duplicado e copia os valores do mapa original.
 * 
 * @param map: Estrutura contendo as informações do mapa original.
 * 
 * @return Retorna um ponteiro para um novo mapa duplicado.
 * 
 * Nota: O usuário é responsável por liberar a memória alocada para o mapa duplicado quando não for mais necessário.
 */
int	**copy_map(t_map *map)
{
	int	**duplicate;
	int	x;
	int	y;

	y = 0;
	duplicate = malloc(sizeof(int *) * map->y / 64);
	while (y < map->y / 64)
	{
		x = 0;
		duplicate[y] = malloc(sizeof(int) * map->x / 64);
		while (x < map->x / 64)
		{
			duplicate[y][x] = map->map[y][x];
			x++;
		}
		y++;
	}
	return (duplicate);
}

/**
 * @brief Inicializa e gera o mapa com base nas informações fornecidas.
 *
 * Esta função inicializa a estrutura de configuração do jogo e a estrutura do mapa usando 'init_map'. Em seguida,
 * aloca dinamicamente memória para uma nova lista encadeada, que será usada para armazenar temporariamente as linhas
 * do mapa lidas do arquivo. A função chama 'read_map' para ler o mapa do arquivo e armazená-lo na lista encadeada.
 * Se a leitura do mapa falhar, a função libera a memória alocada para o mapa e a lista encadeada, e retorna.
 * Após a leitura do mapa, a função calcula as dimensões totais do mapa e define o valor do plano de projeção.
 *
 * @param fd Descritor de arquivo do mapa.
 * @param input Ponteiro para a estrutura de configuração do jogo.
 * @param map Ponteiro para a estrutura do mapa.
 */
static void	init_and_generate_map(int fd, t_config **input, t_map **map)
{
	t_lst	*new;

	init_map(input, map);
	if (!*map)
		return ;
	new = (t_lst *)malloc(sizeof(t_lst));
	new->next = NULL;
	new->content = NULL;
	(*map)->map = read_map(fd, input, new);
	if (!(*map)->map)
	{
		free_map(*map);
		*map = NULL;
		return ;
	}
	(*map)->y = (*input)->height * 64;
	(*map)->x = (*input)->width * 64;
	(*map)->plane = ((*map)->x / 2) / tan(FOV / 2);
}

/**
 * @brief Carrega as configurações do mapa.
 *
 * Esta função chama 'read_and_process_file' para ler e processar as informações do arquivo de configuração.
 * Em seguida, verifica se as texturas e as cores são válidas usando 'verify_textures' e 'verify_colors'.
 * Se alguma verificação falhar, a função libera a memória alocada para as configurações e o mapa, e retorna.
 * Se todas as verificações são bem-sucedidas, a função chama 'init_and_generate_map' para inicializar e gerar o mapa.
 *
 * @param input Ponteiro para a estrutura de configuração do jogo.
 * @param map Ponteiro para a estrutura do mapa.
 */
void	load_map(t_config **input, t_map **map)
{
	if (!read_and_process_file(input) 
		|| (verify_textures(*input) == -1)
		|| (verify_colors(*input) == -1))
	{
		free_input(*input);
		*map = NULL;
		return ;
	}
	init_and_generate_map((*input)->fd, input, map);
}
