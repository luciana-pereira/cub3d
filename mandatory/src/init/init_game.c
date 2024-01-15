/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 05:04:58 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/13 05:07:35 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int init_game(t_config *input, t_map **map, t_player **player)
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