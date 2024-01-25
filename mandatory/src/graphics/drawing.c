/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:16:21 by luizedua          #+#    #+#             */
/*   Updated: 2024/01/25 14:12:56 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	paint_img(t_image *image, int x, int y, int color)
{
	char	*dest;

	if (x > WIN_W || y > WIN_H || x < 0 || y < 0)
		return ;
	dest = (char *)image->data + (y * image->size_line + x * (image->bpp / 8));
	*(unsigned int *)dest = color;
}

void	print_map(t_config *input, int **map_matrix)
{
	int		row;
	int		col;
	char	code_to_char;

	row = 0;
	while (row < (int)input->height / 64)
	{
		col = 0;
		while (col < (int)input->width / 64)
		{
			code_to_char = map_matrix[row][col] + '0';
			write(1, &code_to_char, 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}
