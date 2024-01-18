/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 05:04:58 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/13 05:07:35 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/**
 * @brief Inicializa a biblioteca gráfica e cria uma imagem variável no contexto do jogo.
 *
 * Esta função desempenha um papel crucial na inicialização da biblioteca gráfica para o jogo. 
 * Utilizando o ponteiro `addr` fornecido, ela cria uma imagem variável com dimensões especificadas
 * por WIN_W e WIN_H. Os detalhes essenciais da imagem, incluindo o ponteiro para os dados,
 * a quantidade de bits por pixel (bpp), o comprimento da linha (size_line) e a ordem dos
 * bytes (endian), são encapsulados na estrutura `t_image`.
 *
 * @param game Ponteiro para a estrutura principal do jogo.
 * @return Uma estrutura `t_image` contendo informações vitais da imagem recém-criada.
 *
 * A função também invoca operações adicionais, como o carregamento de texturas através da 
 * função auxiliar `load_textures`. Além disso, estabelece ganchos (hooks) para a manipulação
 * de eventos, como a renderização de quadros com `render_frame`, a detecção de pressionamento
 * de teclas com `key_press`, e a manipulação do evento de fechamento de janela com `close_win`.
 * Por fim, a função entra em um loop infinito através de `mlx_loop`, garantindo a execução
 * contínua do jogo.
 */
void	init_mlx_hooks(t_game *game)
{
	load_textures(game);
	mlx_loop_hook(game->p_mlx, &render_frame, game);
	mlx_hook(game->p_win, 02, (1L << 0), key_press, game);
	mlx_hook(game->p_win, 17, (1L << 2), close_win, game);
	mlx_hook(game->p_win, 4, 0, mouse_hook, game);
	mlx_loop(game->p_mlx);
}

/**
 * @brief Inicializa a biblioteca gráfica e cria uma imagem variável no contexto do jogo.
 *
 * Esta função cria uma imagem variável utilizando a biblioteca gráfica definida pelo
 * ponteiro `addr`. A imagem é inicializada com largura e altura especificadas por WIN_W
 * e WIN_H, respectivamente. Os detalhes da imagem, como o ponteiro para os dados, a
 * quantidade de bits por pixel (bpp), o comprimento da linha (size_line) e a ordem dos
 * bytes (endian), são armazenados na estrutura `t_image`.
 *
 * @param game Ponteiro para a estrutura principal do jogo.
 * @return Uma estrutura `t_image` contendo as informações da imagem criada.
 */
void	init_mlx(t_game	*game)
{
	game->p_mlx = mlx_init();
	if (game->p_mlx == NULL)
		return (exit_with_error(ERROR_MLX, game));
	game->p_win = mlx_new_window(game->p_mlx, WIN_W, WIN_H, "cub3D");
	if (game->p_win == NULL)
		return (exit_with_error(ERROR_MLX_WIN, game));
	game->img.p_img = mlx_new_image(game->p_mlx, WIN_W, WIN_H);
	game->img.data = (int *)mlx_get_data_addr(game->img.p_img, &game->img.bpp,
			&game->img.size_line, &game->img.endian);
}
