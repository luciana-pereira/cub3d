/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_oper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:01:11 by luizedua          #+#    #+#             */
/*   Updated: 2024/01/18 15:22:54 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

float	fix_ang(float angle)
{
	float	two_pi;

	two_pi = M_PI * 2.0f;
	angle = remainder(angle, two_pi);
	if (angle < 0)
		angle += two_pi;
	return (angle);
}

float	distance(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

float	radians(float degrees)
{
	return (degrees * M_PI / 180);
}
