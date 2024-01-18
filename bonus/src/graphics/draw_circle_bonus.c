/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 23:48:17 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/18 16:42:50 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void	draw_circle_row(t_image *img, int xy[2], int c_xy[2], int radius)
{
	while (xy[1] <= c_xy[0] + radius)
	{
		if ((xy[0] - c_xy[0]) * (xy[0] - c_xy[0]) + (xy[1] - c_xy[1]) * \
					(xy[1] - c_xy[1])
			< radius * radius)
			paint_img(img, xy[0], xy[1], COLOR_RED);
		xy[1]++;
	}
}

void	draw_circle(t_image *image, int center_x, int center_y, int radius)
{
	int	xy[2];
	int	center_xy[2];

	center_xy[0] = 0;
	center_xy[1] = 0;
	xy[0] = center_x - radius;
	paint_img(image, center_x, center_y, COLOR_RED);
	while (xy[0] <= center_x + radius)
	{
		xy[1] = center_y - radius;
		center_xy[0] = center_x;
		center_xy[1] = center_y;
		draw_circle_row(image, xy, center_xy, radius);
		xy[0]++;
	}
}
