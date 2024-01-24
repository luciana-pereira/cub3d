/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/24 11:58:50 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void	load_xpm(t_game *game, t_image *img, char *path)
{
	int	width;
	int	height;

	img->p_img = mlx_xpm_file_to_image(game->p_mlx, path, &width, &height);
	img->i_add = mlx_get_data_addr(img->p_img, &img->bpp, &img->size_line,
			&img->endian);
}

void	load_textures(t_game *game)
{
	load_xpm(game, &game->north, game->map->north);
	load_xpm(game, &game->south, game->map->south);
	load_xpm(game, &game->east, game->map->east);
	load_xpm(game, &game->west, game->map->west);
}
