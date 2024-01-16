/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intercept.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/07 18:41:30 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	update_ray_distances(t_rays *ray, t_hit *horz, t_hit *vert)
{
	if (horz->distance > vert->distance)
	{
		ray->fdist = vert->distance;
		ray->hit_x = vert->hit_x;
		ray->hit_y = vert->hit_y;
		ray->is_hit = 1;
	}
	else
	{
		ray->fdist = horz->distance;
		ray->hit_x = horz->hit_x;
		ray->hit_y = horz->hit_y;
		ray->is_hit = 0;
	}
}

/**
 * @brief Calcula a distância entre o jogador e um ponto de intercepção.
 *
 * Esta função calcula a distância entre o jogador e um ponto de intercepção
 * fornecido pela estrutura `t_hit`. A distância é calculada apenas se a
 * intercepção atingir uma parede, caso contrário, FLT_MAX é retornado.
 *
 * @param p Ponteiro para a estrutura que representa o jogador.
 * @param h Estrutura `t_hit` contendo informações sobre a intercepção.
 * @return A distância entre o jogador e o ponto de intercepção, ou FLT_MAX se não houver intercepção.
 */
static float	calc_dist_player(t_player *p, t_hit h)
{
	if (h.hitted)
		return (distance(p->x, p->y, h.hit_x, h.hit_y));
	else
		return (FLT_MAX);
}

/**
 * @brief Calcula a intercepção vertical de um raio com as paredes do mapa.
 *
 * Esta função calcula a intercepção vertical de um raio emitido por um jogador
 * com as paredes do mapa. Utiliza as coordenadas do jogador, o ângulo do raio
 * e a estrutura `t_hit` para armazenar os resultados. Além disso, calcula os passos
 * necessários para avançar verticalmente e incrementa a posição vertical do raio
 * até encontrar uma parede.
 *
 * @param game Ponteiro para a estrutura principal do jogo.
 * @param ray Estrutura que representa o raio.
 * @return Uma estrutura `t_hit` contendo os resultados da intercepção vertical.
 */
t_hit	cal_coord_intercept(t_game *game, t_rays ray, char dir)
{
	t_hit	coord;

	calculate_intercept(game->player, ray, &coord, dir);
	calculate_steps(ray, &coord, dir);
	increment_position(game->map, ray, &coord, dir);
	if (dir == 'v')
		coord.distance = calc_dist_player(game->player, coord);
	else
		coord.distance = calc_dist_player(game->player, coord);
	return (coord);
}

/**
 * @brief Encontra a parede mais próxima entre a intercepção horizontal e vertical.
 *
 * Esta função determina qual intercepção (horizontal ou vertical) possui a parede
 * mais próxima em relação ao jogador. Utiliza a correção de fish-eye para ajustar
 * as distâncias. Os resultados são armazenados nas estruturas `t_hit` fornecidas.
 *
 * @param h Ponteiro para a estrutura `t_hit` da intercepção horizontal.
 * @param v Ponteiro para a estrutura `t_hit` da intercepção vertical.
 * @param p Ponteiro para a estrutura `t_player` que representa o jogador.
 * @param angle Ângulo do raio em relação ao jogador.
 */
void	find_wall(t_hit *h, t_hit *v, t_player *p, float angle)
{
	if (h->hitted)
		h->distance = h->distance * cos(p->angle - angle);
	else
		h->distance = FLT_MAX;
	if (v->hitted)
		v->distance = v->distance * cos(p->angle - angle);
	else
		v->distance = FLT_MAX;
}

/**
 * @brief Calcula a intercepção vertical de um raio com as paredes do mapa.
 *
 * Esta função calcula a intercepção vertical de um raio emitido por um jogador
 * com as paredes do mapa. Utiliza as coordenadas do jogador, o ângulo do raio
 * e a estrutura `t_hit` para armazenar os resultados. Além disso, calcula os passos
 * necessários para avançar verticalmente e incrementa a posição vertical do raio
 * até encontrar uma parede.
 *
 * @param game Ponteiro para a estrutura principal do jogo.
 * @param player Estrutura que representa o jogador.
 * @param ray Estrutura que representa o raio.
 * @return Uma estrutura `t_hit` contendo os resultados da intercepção vertical.
 */
void	calc_vert_ray_intercept(t_game *game, t_player *player, t_rays *ray)
{
	t_hit	horz;
	t_hit	vert;

	horz = cal_coord_intercept(game, *ray, 'h');
	vert = cal_coord_intercept(game, *ray, 'v');
	find_wall(&horz, &vert, player, ray->angle);
	update_ray_distances(ray, &horz, &vert);
}
