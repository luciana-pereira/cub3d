/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:47:11 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/14 00:14:00 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	destroy_images(t_game *game)
{
	mlx_destroy_image(game->p_mlx, game->img.p_img);
	mlx_destroy_image(game->p_mlx, game->north.p_img);
	mlx_destroy_image(game->p_mlx, game->south.p_img);
	mlx_destroy_image(game->p_mlx, game->west.p_img);
	mlx_destroy_image(game->p_mlx, game->east.p_img);
}

static void	free_game_resources(t_game *game)
{
	free_map(game->map);
	free(game->player);
	if (game->p_mlx)
	{
		mlx_destroy_window(game->p_mlx, game->p_win);
		destroy_images(game);
		mlx_destroy_display(game->p_mlx);
		free(game->p_mlx);
	}
}

void free_game(t_game *game)
{
	free_game_resources(game);
	free(game);
}

/**
 * @brief Libera os recursos associados à estrutura do jogo e encerra o programa.
 *
 * Esta função é responsável por liberar os recursos alocados dinamicamente na estrutura
 * do jogo (t_game) e encerrar o programa. Ela utiliza a função free_resources para
 * realizar a liberação de memória associada à estrutura do jogo. Após a liberação de
 * recursos, a função imprime uma mensagem de saída usando ft_printf e chama exit(0) para
 * encerrar o programa.
 *
 * @param game Ponteiro para a estrutura principal do jogo.
 * @return Sempre retorna 0 após a execução.
 */
int	close_win(t_game *game)
{
    free_game(game);
    write(1, EXIT_THE_GAME, sizeof(EXIT_THE_GAME) - 1);
    exit(0);
    return (0);
}

/**
** Libera a memória alocada para a estrutura t_config, incluindo os caminhos das texturas se estiverem presentes.
** 
* @param input: ponteiro para a estrutura t_config a ser liberada.
** 
** Nota: Os caminhos das texturas são liberados apenas se as respectivas flags estiverem definidas.
*/
void	free_input(t_config *input)
{
	if (input)
	{
		if (input->tex.west)
			free(input->tex.west_path);
		if (input->tex.east)
			free(input->tex.east_path);
		if (input->tex.north)
			free(input->tex.north_path);
		if (input->tex.south)
			free(input->tex.south_path);
		close(input->fd);
		free(input);
	}
}
