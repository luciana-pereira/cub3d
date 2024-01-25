/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_obtaining_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:45:42 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/25 14:07:27 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	cal_wall_dimension(t_game *game, int coord[2], int invert, int *offset)
{
	float	height;
	int		dist_to_top;

	height = (64 / game->rays[coord[0]].fdist) * game->map->plane;
	if (invert)
		offset[0] = (invert - calc_horizontal_disp(game->rays[coord[0]]));
	else
		offset[0] = calc_horizontal_disp(game->rays[coord[0]]);
	dist_to_top = coord[1] + (floor(height) / 2) - ((float)WIN_H / 2);
	offset[1] = dist_to_top * ((float)64 / floor(height));
}

static int	get_texture_color(t_image texture, int offset[2])
{
	return (*(unsigned int *)(texture.i_add + (offset[1] * texture.size_line + \
		offset[0] * (texture.bpp / 8))));
}

int	get_texture(t_game *game, t_image texture, int coord[2], int invert)
{
	int	offset[2];

	cal_wall_dimension(game, coord, invert, offset);
	return (get_texture_color(texture, offset));
}
