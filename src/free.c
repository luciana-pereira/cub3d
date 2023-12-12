/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2023/12/10 03:00:26 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_array(char ***array)
{
	int	index;

	index = 0;
	while (array && array[0] && array[0][index])
	{
		free(array[0][index]);
		index++;
	}
	if (array)
	{
		free(array[0]);
		*array = NULL;
	}
}

void	destroy_image(t_game *game)
{
	
    // Mesma logica para a textura -> free_texture(game);
	if (game->win)
		mlx_destroy_image(game->mlx, game->win);
}

void	free_game_memory(t_game *game)
{
	if (!game)
		return ;
	free_array(&game->map);
	destroy_image(game);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}
