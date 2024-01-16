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

#include "../../includes/cub3d.h"

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
** Carrega o mapa a partir das informações fornecidas na estrutura de entrada (t_config).
** Retorna um ponteiro para a estrutura do mapa (t_map) se bem-sucedido, ou NULL em caso de erro.
** 
** @param input: ponteiro para a estrutura de entrada contendo informações do arquivo de configuração.
** 
** Nota: Esta função utiliza as funções read_and_process_file, verify_tex_and_colors e create_map.
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
