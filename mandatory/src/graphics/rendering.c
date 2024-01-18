/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/14 23:28:59 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * @brief Renderiza a cena do jogo.
 *
 * Esta função realiza o processo de renderização da cena do jogo. Inclui a
 * geração do plano de fundo, o lançamento de raios para calcular a projeção
 * tridimensional e a exibição da imagem resultante na janela. Utiliza as
 * funções auxiliares, `cast_and_generate_projection`.
 *
 * @param game Ponteiro para a estrutura principal do jogo.
 * @return Um valor inteiro indicando o término da função (0 para sucesso).
 */
int	render_frame(t_game *game)
{
	int	col;
	int	row;
	int	ceiling;
	int	floor;

	row = 0;
	floor = game->map->floor;
	ceiling = game->map->ceiling;
	while (row < WIN_H / 2)
	{
		col = 0;
		while (col < WIN_W)
		{
			paint_img(&game->img, col, row, ceiling);
			paint_img(&game->img, col, row + WIN_H / 2, floor);
			col++;
		}
		row++;
	}
	cast_and_generate_projection(game);
	mlx_put_image_to_window(game->p_mlx, game->p_win, game->img.p_img, 0, 0);
	return (0);
}
