/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/24 15:07:32 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"
#include <stdio.h>

void	paint_img(t_image *image, int x, int y, int color)
{
	char	*dest;

	if (x > WIN_W || y > WIN_H || x < 0 || y < 0)
		return ;
	dest = (char *)image->data + (y * image->size_line + x * (image->bpp / 8));
	*(unsigned int *)dest = color;
}

void	print_map(t_config *input, int **map)
{
	size_t	row;
	size_t	col;

	row = 0;
	if (!map)
		return ;
	while (row < input->height)
	{
		col = 0;
		while (col < input->width)
		{
			printf("%i", map[row][col]);
			col++;
		}
		printf("\n");
		row++;
	}
}
