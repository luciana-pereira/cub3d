/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/07 20:29:40 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/**
 * @brief Carrega uma imagem XPM e inicializa a estrutura de imagem.
 *
 * Esta função carrega uma imagem XPM do caminho especificado e inicializa a estrutura de imagem
 * fornecida com as informações da imagem carregada.
 *
 * @param game Ponteiro para a estrutura principal do jogo.
 * @param img Ponteiro para a estrutura de imagem a ser inicializada.
 * @param path Caminho do arquivo XPM.
 */
static void	load_xpm(t_game *game, t_image *img, char *path)
{
	int	width;
	int	height;

	img->p_img = mlx_xpm_file_to_image(game->p_mlx, path, &width, &height);
	img->i_add = mlx_get_data_addr(img->p_img, &img->bpp, &img->size_line,
			&img->endian);
}


/**
 * @brief Carrega as texturas necessárias para os diferentes pontos cardeais do jogo.
 *
 * Esta função é responsável por carregar as texturas associadas às direções norte, sul, leste e oeste do jogo.
 * Utiliza a função auxiliar 'load_xpm' para carregar cada textura com base nos caminhos especificados no mapa do jogo.
 *
 * @param game Ponteiro para a estrutura principal do jogo.
 */
void	load_textures(t_game *game)
{
	load_xpm(game, &game->north, game->map->north);
	load_xpm(game, &game->south, game->map->south);
	load_xpm(game, &game->east, game->map->east);
	load_xpm(game, &game->west, game->map->west);
}
