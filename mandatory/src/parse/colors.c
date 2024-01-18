/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:00:31 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/18 01:49:42 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * @brief Verifica se as cores do teto e do chão foram definidas corretamente.
 *
 * Esta função verifica se as cores do teto e do chão foram especificadas corretamente
 * no arquivo de configuração do jogo. Se ambas as cores não foram definidas, a função
 * imprime uma mensagem de erro indicando que as cores são inválidas e retorna um código
 * de erro correspondente.
 *
 * @param input Ponteiro para a estrutura de configuração do jogo.
 * @return 0 se as cores estiverem definidas corretamente, caso contrário, um código de erro.
 */
int	verify_colors(t_config *input)
{
	if (!input->ceiling)
		return (print_error(INVALID_CEILING));
	if (!input->floor)
		return (print_error(INVALID_FLOOR));
	return (0);
}

/**
 * @brief Verifica se um conjunto de valores representa uma cor RGB válida.
 *
 * Esta função recebe valores para os componentes de cor (vermelho, verde e azul) e
 * verifica se estão dentro do intervalo permitido (0 a 255). Caso algum valor esteja
 * fora do intervalo, a função chama `print_error` para exibir uma mensagem de erro.
 *
 * @param red Valor do componente vermelho da cor.
 * @param green Valor do componente verde da cor.
 * @param blue Valor do componente azul da cor.
 */
static void	is_valid_color(int red, int green, int blue)
{
	if ((red < 0 || red > 255) || (blue < 0 || blue > 255)
		|| (green < 0 || green > 255))
		print_error(INVALID_RGBD_COLOR);
}

/**
 * @brief Converte um array de strings representando uma cor RGB para um valor inteiro.
 *
 * Esta função converte uma cor RGB representada por um array de strings para um valor inteiro.
 * Os componentes vermelho (red), verde (green) e azul (blue) são extraídos do array e validados usando a função
 * 'is_valid_color'. A fórmula de conversão é aplicada para calcular o valor inteiro representando a cor.
 *
 * @param color Array de strings representando a cor RGB.
 * @return Valor inteiro representando a cor.
 */
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
 * @brief Remove espaços em branco de cada componente de uma cor representada por um array de strings.
 *
 * Esta função remove espaços em branco de cada componente de uma cor representada por um array de strings.
 * Itera sobre os três componentes (red, green, blue), utiliza a função 'remove_whitespaces' para remover
 * espaços em branco, libera a string original e substitui pelo resultado sem espaços em branco.
 *
 * @param color Array de strings representando a cor RGB.
 * @return Array de strings representando a cor sem espaços em branco.
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

/**
 * @brief Processa a representação de uma cor e a converte para um valor inteiro.
 *
 * Esta função remove espaços em branco de cada componente da cor, verifica se cada componente é numérico,
 * converte a cor para um valor inteiro usando 'convert_rgb' e libera a memória alocada para a representação da cor.
 * Se a conversão falhar ou se algum componente não for numérico, a função imprime um erro e retorna -1.
 *
 * @param color Array de strings representando a cor RGB.
 * @param arg Ponteiro para o valor inteiro que representará a cor processada.
 * @return 0 em caso de sucesso, -1 em caso de erro.
 */
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
