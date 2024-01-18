/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graph_env_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:52:37 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/18 13:28:32 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/**
 * @brief Inicializa o ambiente gráfico e os ganchos do mlx.
 *
 * Esta função recebe um ponteiro para a estrutura do jogo e inicializa o ambiente
 * gráfico e os ganchos do mlx. Ela chama as funções `init_mlx` e `init_mlx_hooks`.
 *
 * @param game Ponteiro para a estrutura do jogo.
 * @return Um ponteiro para a estrutura do jogo recém-criada.
 */
static void	mlx_hooks(t_game *game)
{
	init_mlx(game);
	init_mlx_hooks(game);
}

/**
 * @brief Inicializa a estrutura do jogo.
 *
 * Esta função cria e inicializa a estrutura do jogo, alocando memória para as
 * variáveis necessárias, como a estrutura do jogo, os raios e os ganchos do mlx.
 * Em caso de erro durante a alocação de memória, ela chama a função `exit_with_error`
 * e libera a memória alocada anteriormente.
 *
 * @param game Ponteiro para a estrutura do jogo.
 * @param player Ponteiro para a estrutura do jogador.
 */
void	init_graph_env(t_map *map, t_player *player)
{
	t_game	*game;
	t_rays	ray[WIN_W];

	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (game == NULL)
	{
		free_map(map);
		free(player);
		free(game);
		exit_with_error(ERROR_CALLOC, NULL);
	}
	game->map = map;
	game->player = player;
	game->num_rays = WIN_W;
	game->rays = ray;
	game->mouse = 1;
	mlx_hooks(game);
}
