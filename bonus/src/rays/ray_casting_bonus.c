/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/17 21:19:35 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	is_facing(float angle, int direction)
{
	if (direction == 0) // Em baixo
		return (angle > 0 && angle < M_PI);
	else if (direction == 1) // Em cima
		return (!is_facing(angle, 0));
	else if (direction == 2) // Esquerda
		return (angle < 0.5 * M_PI || angle > 1.5 * M_PI);
	else if (direction == 3) // Direita
		return (!is_facing(angle, 2));
	return (0); // Direção invalida
}

// Correção do angulo
/**
 * @brief Verifica se o jogador está voltado para uma determinada direção.
 *
 * Esta função verifica se o jogador está voltado para uma determinada direção
 * com base no ângulo e na direção especificada. Retorna 1 se estiver voltado para a direção,
 * 0 caso contrário. Se a direção especificada for inválida, retorna 0.
 *
 * @param angle Ângulo do jogador.
 * @param direction Direção para a qual verificar a orientação do jogador.
 *                  0 - Em baixo, 1 - Em cima, 2 - Esquerda, 3 - Direita.
 * @return 1 se o jogador estiver voltado para a direção, 0 caso contrário ou se a direção for inválida.
 */
static void	init_ray_directions(t_rays *ray, float angle)
{
	ray->angle = angle;
	ray->vy = is_facing(ray->angle, 0);
	ray->vx = is_facing(ray->angle, 1);
	ray->hx = is_facing(ray->angle, 2);
	ray->hy = is_facing(ray->angle, 3);
}

/**
 * @brief Inicializa a estrutura de raio com base no ângulo fornecido.
 *
 * Esta função configura a estrutura de raio `t_rays` com o ângulo especificado
 * e calcula as direções em que o raio está enfrentando. Além disso, inicializa
 * outras propriedades do raio, como a posição inicial, a distância, e as coordenadas
 * do ponto de impacto.
 *
 * @param ray Ponteiro para a estrutura de raio `t_rays`.
 * @param player Ponteiro para a estrutura de jogador `t_player`.
 * @param angle Ângulo do raio em radianos.
 * @return Nenhum valor de retorno.
 */
void	init_ray(t_rays *ray, t_player *player, float angle)
{
	init_ray_directions(ray, angle);
	ray->rx = player->x;
	ray->ry = player->y;
	ray->fdist = 0;
	ray->hit_x = 0;
	ray->hit_y = 0;
	ray->is_hit = 0;
}

/**
 * @brief Realiza o lançamento de raios e gera a projeção na tela.
 *
 * Esta função lança raios na cena e gera a projeção na tela para cada pixel da coluna.
 * Inicializa a estrutura de raio para cada pixel, calcula a interseção do raio com as paredes
 * usando 'calc_vert_ray_intercept' e desenha as paredes na tela usando 'draw_wall'.
 *
 * @param game Ponteiro para a estrutura principal do jogo.
 */
void	cast_and_generate_projection(t_game *game)
{
	float	angle;
	int		pixel_col;
	int		top_pixel;
	int		bottom_pixel;

	pixel_col = 0;
	angle = game->player->angle - 0.523599;
	while (pixel_col < game->num_rays)
	{
		angle = fix_ang(angle);
		init_ray(&game->rays[pixel_col], game->player, angle);
		calc_vert_ray_intercept(game, game->player, &game->rays[pixel_col]);
		angle += FOV / game->num_rays;
		top_pixel = calculate_position(game, pixel_col, 1);
		bottom_pixel = calculate_position(game, pixel_col, 0);
		draw_wall(game, pixel_col, top_pixel, bottom_pixel);
		pixel_col++;
	}
}
