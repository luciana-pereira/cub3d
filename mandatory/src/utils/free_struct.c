/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:47:11 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/26 04:18:29 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	destroy_images(t_game *game)
{
	mlx_destroy_image(game->p_mlx, game->img.p_img);
	mlx_destroy_image(game->p_mlx, game->north.p_img);
	mlx_destroy_image(game->p_mlx, game->south.p_img);
	mlx_destroy_image(game->p_mlx, game->west.p_img);
	mlx_destroy_image(game->p_mlx, game->east.p_img);
}

static void	free_game_resources(t_game *game)
{
	free_map(game->map);
	free(game->player);
	if (game->p_mlx)
	{
		mlx_destroy_window(game->p_mlx, game->p_win);
		destroy_images(game);
		mlx_destroy_display(game->p_mlx);
		free(game->p_mlx);
	}
}

void	free_game(t_game *game)
{
	free_game_resources(game);
	free(game);
}

int	close_win(t_game *game)
{
	free_game(game);
	exit(0);
	return (0);
}

void	free_input(t_config *input)
{
	if (input)
	{
		if (input->tex.west)
			free(input->tex.west_path);
		if (input->tex.east)
			free(input->tex.east_path);
		if (input->tex.north)
			free(input->tex.north_path);
		if (input->tex.south)
			free(input->tex.south_path);
		if (input->fd > 0)
			close(input->fd);
		free(input);
	}
}
