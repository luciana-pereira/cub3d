/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graph_env_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:52:37 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/23 10:16:38 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void	mlx_hooks(t_game *game)
{
	init_mlx(game);
	init_mlx_hooks(game);
}

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
	// print_map(game->map, game->map->map);
	mlx_hooks(game);
}
