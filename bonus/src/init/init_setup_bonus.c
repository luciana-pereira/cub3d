/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_setup_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/13 05:08:54 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/**
 * @brief Inicializa a estrutura de configuração do jogo.
 *
 * Esta função é responsável por inicializar a estrutura `t_config` fornecida, configurando
 * todos os campos para seus valores padrão. Esses campos incluem as coordenadas iniciais do
 * jogador, as dimensões do mapa, as cores do piso e do teto, além das texturas para as 
 * direções norte, sul, oeste e leste. A função serve como um ponto de partida para preparar
 * a configuração do jogo antes de iniciar a carga do mapa e a validação subsequente.
 *
 * @param input Ponteiro para a estrutura `t_config` que será inicializada.
 */
void	init_structure(t_config *input)
{	
	input->px = 0;
	input->py = 0;
	input->player = 0;
	input->width = 0;
	input->height = 0;
	input->floor = 0;
	input->ceiling = 0;
	input->tex.north = 0;
	input->tex.south = 0;
	input->tex.west = 0;
	input->tex.east = 0;
	input->floor_color = 0;
	input->ceiling_color = 0;
}

/**
 * @brief Inicializa a estrutura t_config e atribui um descritor de arquivo ao campo fd.
 * Retorna um ponteiro para a estrutura t_config inicializada ou NULL em caso de erro.
 * 
 * @param input Ponteiro para a estrutura que contém as informações de entrada.
 * @param argv: vetor de argumentos do programa.
 * Nota: A função pode exibir uma mensagem de erro usando print_error se falhar ao abrir o arquivo.
 */
void	init_settings(t_config *input, char **argv)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		print_error(strerror(errno));
		return ;
	}
	input->fd = fd;
}
