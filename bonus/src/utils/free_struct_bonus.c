/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/18 16:09:39 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

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
	write(1, EXIT_THE_GAME, sizeof(EXIT_THE_GAME) - 1);
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
		close(input->fd);
		free(input);
	}
}
