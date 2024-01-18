/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:47:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/18 15:30:05 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_mlx_hooks(t_game *game)
{
	load_textures(game);
	mlx_loop_hook(game->p_mlx, &render_frame, game);
	mlx_hook(game->p_win, 02, (1L << 0), key_press, game);
	mlx_hook(game->p_win, 17, (1L << 2), close_win, game);
	mlx_loop(game->p_mlx);
}

void	init_mlx(t_game	*game)
{
	game->p_mlx = mlx_init();
	if (game->p_mlx == NULL)
		return (exit_with_error(ERROR_MLX, game));
	game->p_win = mlx_new_window(game->p_mlx, WIN_W, WIN_H, "cub3D");
	if (game->p_win == NULL)
		return (exit_with_error(ERROR_MLX_WIN, game));
	game->img.p_img = mlx_new_image(game->p_mlx, WIN_W, WIN_H);
	game->img.data = (int *)mlx_get_data_addr(game->img.p_img, &game->img.bpp,
			&game->img.size_line, &game->img.endian);
}
