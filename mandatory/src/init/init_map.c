/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:03:34 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/13 21:38:01 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * @brief Inicializa a estrutura do mapa com base nas configurações fornecidas.
 *
 * Esta função aloca dinamicamente a estrutura do mapa e a inicializa com as cores de piso e teto, além dos caminhos
 * para as texturas nas direções leste, oeste, norte e sul. Os dados são extraídos da estrutura de configuração fornecida.
 *
 * @param input Ponteiro para o ponteiro da estrutura de configuração do jogo.
 * @param map Ponteiro para o ponteiro da estrutura do mapa.
 */
void	init_map(t_config **input, t_map **map)
{
	*map = malloc(sizeof(t_map));
	if (!*map)
		return ;
	(*map)->floor = (*input)->floor_color;
	(*map)->ceiling = (*input)->ceiling_color;
	(*map)->east = ft_strdup((*input)->tex.east_path);
	(*map)->west = ft_strdup((*input)->tex.west_path);
	(*map)->north = ft_strdup((*input)->tex.north_path);
	(*map)->south = ft_strdup((*input)->tex.south_path);
}
