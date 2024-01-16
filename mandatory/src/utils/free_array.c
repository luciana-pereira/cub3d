/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/13 17:55:59 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
** Libera a memória alocada para um array bidimensional.
**
** @param array: ponteiro para o array bidimensional.
** @param y: número de linhas do array.
*/
void	free_2d_array(int **matrix, int rows)
{
	if (matrix == NULL)
		return ;
	while (rows-- > 0)
	{
		free(matrix[rows]);
		matrix[rows] = NULL;
	}
	free(matrix);
}


void	free_array(char **array)
{
	int	index;

	index = 0;
	while (array[index])
	{
		free(array[index]);
		index++;
	}
	free(array);
}
