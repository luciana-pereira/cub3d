/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 05:04:58 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/13 05:07:35 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/**
 * @brief Inicializa o jogo carregando o mapa e configurando o jogador.
 *
 * Esta função inicializa o jogo carregando o mapa com base nas configurações fornecidas e configurando o jogador.
 * Se o carregamento do mapa falhar ou o mapa não for válido, a função libera os recursos alocados e retorna -1.
 * Se a inicialização do jogador falhar, a função também libera os recursos alocados e retorna -1.
 *
 * @param input Ponteiro para a estrutura de configuração do jogo.
 * @param map Ponteiro para o ponteiro da estrutura do mapa.
 * @param player Ponteiro para o ponteiro da estrutura do jogador.
 * @return 0 em caso de sucesso, -1 em caso de falha.
 */
int	init_game(t_config *input, t_map **map, t_player **player)
{
	*map = NULL;
	load_map(&input, map);
	if (*map == NULL)
		return (-1);
	if ((*map)->map == NULL)
	{
		free_map(*map);
		return (-1);
	}
	if (is_valid_map_path(*map, input->py, input->px) == -1)
	{
		free_map(*map);
		free_input(input);
		return (-1);
	}
	if (init_player(player, input->py, input->px, input->player_dir) != 0)
	{
		free_map(*map);
		free_input(input);
		return (-1);
	}
	return (0);
}
