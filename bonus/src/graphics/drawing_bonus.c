/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/18 16:28:58 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	paint_img(t_image *image, int x, int y, int color)
{
	char	*dest;

	if (x > WIN_W || y > WIN_H || x < 0 || y < 0)
		return ;
	dest = (char *)image->data + (y * image->size_line + x * (image->bpp / 8));
	*(unsigned int *)dest = color;
}

void	print_map(t_map *map, int **map_matrix)
{
	int		row;
	int		col;
	char	code_to_char;

	row = 0;
	while (row < (int)map->y / 64)
	{
		col = 0;
		while (col < (int)map->x / 64)
		{
			code_to_char = map_matrix[row][col] + '0';
			write(1, &code_to_char, 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}
