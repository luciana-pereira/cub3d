/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/07 18:41:30 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
** Carrega uma textura XPM para a imagem.
** 
* @param game: Estrutura principal do jogo.
* @param img: Estrutura de imagem onde a textura será carregada.
* @param path: Caminho do arquivo XPM.
** 
** Nota: Esta função utiliza as funções mlx_xpm_file_to_image e mlx_get_data_addr.
*/
void	load_xpm(t_game *game, t_image *img, char *path)
{
	int		width;
	int		height;

	img->p_img = mlx_xpm_file_to_image(game->p_mlx, path, &width, &height);
	img->i_add = mlx_get_data_addr(img->p_img, &img->bpp, &img->size_line,
			&img->endian);
}

/**
** Carrega as texturas do jogo a partir dos caminhos fornecidos no mapa.
** Utiliza a função load_xpm para carregar cada textura.
** 
* @param game: ponteiro para a estrutura principal do jogo (game).
*/
void	load_textures(t_game *game)
{
	load_xpm(game, &game->north, game->map->north);
	load_xpm(game, &game->south, game->map->south);
	load_xpm(game, &game->east, game->map->east);
	load_xpm(game, &game->west, game->map->west);
}
