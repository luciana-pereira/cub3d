/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:50:52 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/13 18:52:07 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * @brief Processa um elemento de configuração na linha.
 *
 * Esta função verifica se a linha contém o elemento de configuração especificado,
 * atualiza a flag correspondente e processa a cor associada. Retorna 0 se o elemento não estiver presente na linha.
 * Retorna o resultado da função 'process_color' se o elemento estiver presente.
 *
 * @param line String contendo a linha a ser verificada.
 * @param flag Ponteiro para a flag associada ao elemento.
 * @param element String representando o elemento a ser processado.
 * @param arg Ponteiro para a variável que armazenará o valor numérico associado ao elemento.
 * @return 0 se o elemento não estiver presente, o resultado de 'process_color' se estiver presente.
 */
static int	process_element(char *line, int *flag, char *element, int *arg)
{
	char **color;

	if (!ft_strncmp(line, element, 2))
	{
		if (*flag)
			return (print_error(INVALID_ELEMENT));
		*flag = 1;
		color = ft_split(line + 1, ',');
		if (!(color[0]) || !(color[1]) || !(color[2]))
		{
			free_array(color);
			return (print_error(INVALID_ELEMENT_COLOR));
		}
		return (process_color(color, arg));
	}
	return (0);
}

/**
 * @brief Verifica e processa o elemento de configuração de chão e teto na linha.
 *
 * Esta função chama 'process_element' para verificar e processar o elemento de configuração
 * de chão e teto na linha. Retorna o resultado de 'process_element'.
 *
 * @param line String contendo a linha a ser verificada.
 * @param arg Ponteiro para a variável que armazenará o valor numérico associado ao elemento.
 * @param element String representando o elemento a ser processado.
 * @param flag Ponteiro para a flag associada ao elemento.
 * @return O resultado de 'process_element'.
 */
int	has_floor_ceiling(char *line, int *arg, char *element, int *flag)
{
	return (process_element(line, flag, element, arg));
}
