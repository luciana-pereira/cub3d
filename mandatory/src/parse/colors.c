/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:00:31 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/18 15:20:52 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * @brief Verifica se as cores do teto e do chão foram definidas corretamente.
 *
 * Esta função verifica se as cores do teto e do chão foram especificadas 
 *corretamente
 * no arquivo de configuração do jogo. Se ambas as cores não foram definidas, 
 *a função
 * imprime uma mensagem de erro indicando que as cores são inválidas e retorna 
 *um código
 * de erro correspondente.
 *
 * @param input Ponteiro para a estrutura de configuração do jogo.
 * @return 0 se as cores estiverem definidas corretamente, caso contrário, um 
 *código de erro.
 */
int	verify_colors(t_config *input)
{
	if (!input->ceiling)
		return (print_error(INVALID_CEILING));
	if (!input->floor)
		return (print_error(INVALID_FLOOR));
	return (0);
}

static void	is_valid_color(int red, int green, int blue)
{
	if ((red < 0 || red > 255) || (blue < 0 || blue > 255)
		|| (green < 0 || green > 255))
		print_error("Invalid RGB color");
}

static int	convert_rgb(char **color)
{
	int	colors;
	int	red;
	int	green;
	int	blue;

	red = ft_atoi(color[0]);
	green = ft_atoi(color[1]);
	blue = ft_atoi(color[2]);
	is_valid_color(red, green, blue);
	colors = RGB_RED * red + RGB_GREEN * green + RGB_BLUE * blue;
	return (colors);
}

/**
** Remove espaços em branco das extremidades de cada componente de uma cor.
** 
* @param color: vetor de strings representando as componentes de uma cor.
** 
** Retorna um novo vetor de strings com as cores ajustadas.
*/
static char	**remove_whitespaces_color(char **color)
{
	char	*temp;
	int		index;

	index = 0;
	while (index < 3)
	{
		temp = remove_whitespaces(color[index]);
		free(color[index]);
		color[index] = temp;
		index++;
	}
	return (color);
}

int	process_color(char **color, int *arg)
{
	color = remove_whitespaces_color(color);
	if (!is_numeric(color[0]) || !is_numeric(color[1]) || !is_numeric(color[2]))
	{
		free_array(color);
		return (print_error(INVALID_ELEMENT_COLOR));
	}
	*arg = convert_rgb(color);
	free_array(color);
	if (*arg == -1)
		return (-1);
	return (0);
}
