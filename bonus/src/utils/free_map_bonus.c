/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/18 02:05:26 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/**
** Libera a memória alocada para a estrutura do mapa e seus elementos.
** 
* @param map: ponteiro para a estrutura do mapa a ser liberada.
** 
** Nota: Certifica-se de liberar a memória para os caminhos das texturas e a matriz do mapa.
*/
void	free_map(t_map *map)
{
	free(map->west);
	free(map->north);
	free(map->south);
	free(map->east);
	free_2d_array(map->map, map->y / 64);
	free(map);
}

/**
** Libera a memória alocada para as linhas do mapa.
**
* @param map_line: ponteiro para a estrutura que representa as linhas do mapa.
**
** Nota: Esta função assume que a alocação de memória foi feita corretamente,
**       e que as strings e a estrutura foram inicializadas corretamente.
*/
void	free_map_lines(t_lst *map_line)
{
	t_lst	*aux;

	if (!map_line)
		return ;
	while (map_line->next)
	{
		aux = map_line;
		map_line = map_line->next;
		free(aux->content);
		free(aux);
	}
	free(map_line->content);
	free(map_line);
}
