/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graph_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 05:04:58 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/22 10:16:41 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	mlx_hooks(game);
}
