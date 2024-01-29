/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_row_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/26 05:51:46 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void	initialize_decision(int *difference, int is_horizontal, \
									int *decision)
{
	if (is_horizontal == 1)
		*decision = (2 * difference[1]) - difference[0];
	else
		*decision = (2 * difference[0]) - difference[1];
}

static void	update_decision(t_coords *start, int *diff, int *decision, \
														t_draw_params *params)
{
	if (params->is_horizontal == 1)
		start->x = start->x + diff[2];
	else
		start->y = start->y + diff[3];
	if (*decision <= 0)
		*decision += (2 * diff[params->is_horizontal % 2]);
	else
	{
		*decision += 2 * (diff[params->is_horizontal % 2] - \
										diff[params->is_horizontal % 2]);
		if (params->is_horizontal == 1)
		{
			*decision += 2 * (diff[params->is_horizontal % 2] - diff[0]);
			start->y = start->y + diff[3];
		}
		else
		{
			*decision += 2 * (diff[params->is_horizontal % 2] - diff[1]);
			start->x = start->x + diff[2];
		}
	}
	paint_img(params->image, start->x, start->y, params->color);
}

void	draw_row_img(t_coords start, t_coords end, t_draw_params *params, \
							int is_horizontal)
{
	int	*difference;
	int	decision;

	paint_img(params->image, start.x, start.y, params->color);
	difference = calculate_diff(start, end);
	initialize_decision(difference, is_horizontal, &decision);
	while ((is_horizontal == 1 && start.x != end.x)
		|| (is_horizontal == 2 && start.y != end.y))
	{
		params->is_horizontal = is_horizontal;
		update_decision(&start, difference, &decision, params);
	}
	paint_img(params->image, end.x, end.y, params->color);
	free(difference);
}

void	draw_row(t_coords start, t_coords end, t_draw_params *params)
{
	int	diff_x;
	int	diff_y;

	diff_x = start.x - end.x;
	diff_y = start.y - end.y;
	if (end.x > start.x)
		diff_x = end.x - start.x;
	if (end.y > start.y)
		diff_y = end.y - start.y;
	if (diff_x >= diff_y)
		draw_row_img(start, end, params, 1);
	else
		draw_row_img(start, end, params, 2);
}
