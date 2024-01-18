/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_diff_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 00:58:58 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/18 04:47:33 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

// Função para obter a diferença em X
static int	get_difference_x(t_coords start, t_coords end)
{
	if (end.x > start.x)
		return (end.x - start.x);
	else
		return (start.x - end.x);
}

// Função para obter a diferença em Y
static int	get_difference_y(t_coords start, t_coords end)
{
	if (end.y > start.y)
		return (end.y - start.y);
	else
		return (start.y - end.y);
}

// Função principal que retorna um array de diferença
int	*calculate_diff(t_coords start, t_coords end)
{
	int	*difference;

	difference = malloc(4 * sizeof(int));
	difference[0] = get_difference_x(start, end);
	difference[1] = get_difference_y(start, end);
	if (end.x > start.x)
		difference[2] = 1;
	else
		difference[2] = -1;
	if (end.y > start.y)
		difference[3] = 1;
	else
		difference[3] = -1;
	return (difference);
}
