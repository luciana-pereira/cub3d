/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/18 16:35:19 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	render_frame(t_game *game)
{
	int	col;
	int	row;
	int	ceiling;
	int	floor;

	row = 0;
	floor = game->map->floor;
	ceiling = game->map->ceiling;
	while (row < WIN_H / 2)
	{
		col = 0;
		while (col < WIN_W)
		{
			paint_img(&game->img, col, row, ceiling);
			paint_img(&game->img, col, row + WIN_H / 2, floor);
			col++;
		}
		row++;
	}
	cast_and_generate_projection(game);
	draw_mini_map(game, game->map);
	mlx_put_image_to_window(game->p_mlx, game->p_win, game->img.p_img, 0, 0);
	return (0);
}
