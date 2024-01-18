/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:42:09 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/17 20:44:27 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/**
 * @brief Verifica os argumentos de linha de comando.
 *
 * Esta função verifica se o número de argumentos é igual a 2 e se a extensão do arquivo é válida.
 * Retorna 0 se os argumentos são válidos, exibindo mensagens de erro caso contrário.
 *
 * @param argc Número de argumentos.
 * @param argv Vetor de strings contendo os argumentos.
 * @return 0 se os argumentos são válidos, mensagens de erro caso contrário.
 */
static int	verify_args(int argc, char **argv)
{
	if (argc != 2)
		return (print_error(INVALID_ARG));
	if (ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), CUB_EXTENSION, 4))
		return (print_error(INVALID_EXT));
	return (0);
}

/**
 * @brief Processa a entrada do usuário e inicializa a estrutura de dados correspondente.
 *
 * Esta função verifica os argumentos de linha de comando, inicializa a estrutura
 * de entrada (`t_config`) e configura as opções do jogo com base nos argumentos.
 *
 * @param argc Número de argumentos de linha de comando.
 * @param argv Array de strings contendo os argumentos de linha de comando.
 * @param input Ponteiro para a estrutura `t_config` que será inicializada.
 * @return 0 em caso de sucesso, -1 em caso de falha.
 */
int	process_input(int argc, char **argv, t_config **input)
{
	if (verify_args(argc, argv) != 0)
		return (-1);
	*input = (t_config *)malloc(sizeof(t_config));
	if (*input == NULL)
		return (-1);
	init_structure(*input);
	init_settings(*input, argv);
	if (*input == NULL)
		return (-1);
	return (0);
}
