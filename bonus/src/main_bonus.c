/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/17 22:03:13 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

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
