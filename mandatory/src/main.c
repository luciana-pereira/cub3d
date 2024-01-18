/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/18 15:31:46 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_config	*input;
	t_map		*map;
	t_player	*player;

	if (process_input(argc, argv, &input) != 0)
		return (-1);
	if (init_game(input, &map, &player) != 0)
		return (-1);
	free_input(input);
	init_graph_env(map, player);
	free(player);
	return (0);
}
