/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 05:04:58 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/25 14:29:53 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	init_game(t_config *input, t_map **map, t_player **player)
{
	*map = NULL;
	if (load_map(&input, map) == -1)
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
