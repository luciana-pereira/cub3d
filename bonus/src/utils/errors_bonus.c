/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/18 02:05:15 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/**
** Exibe uma mensagem de erro, libera a memória associada a uma estrutura t_game e encerra o programa.
** 
* @param str: mensagem de erro a ser exibida.
* @param game: ponteiro para a estrutura t_game cuja memória será liberada.
*/
void	exit_with_error(char *str, t_game *game)
{
	print_error(str);
	if (game)
		free_game(game);
}

/**
 * @brief Exibe uma mensagem de erro no stderr.
 *
 * Esta função é responsável por formatar e exibir mensagens de erro.
 * Ela escreve uma mensagem padrão seguida pela mensagem de erro fornecida como argumento.
 *
 * @param message A mensagem de erro específica a ser exibida.
 * @return -1 para indicar um erro.
 */
int	print_error(char *message)
{
	write(STDERR_FILENO, ERROR_CUB3D, 15);
	write(STDERR_FILENO, message, ft_strlen(message));
	write(STDERR_FILENO, "\n", 1);
	return (-1);
}
