/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/13 20:48:46 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * @brief Calcula a intercepção vertical ou horizontal de um raio com as paredes do mapa.
 *
 * Esta função calcula a intercepção vertical ou horizontal de um raio emitido por um jogador
 * com as paredes do mapa. Utiliza as coordenadas do jogador, o ângulo do raio
 * e a estrutura `t_hit` para armazenar os resultados. A direção da intercepção é
 * determinada pelo parâmetro `dir`.
 *
 * @param player Ponteiro para a estrutura que representa o jogador.
 * @param ray Estrutura que representa o raio.
 * @param hit Estrutura `t_hit` para armazenar os resultados da intercepção.
 * @param dir Caractere indicando a direção da intercepção ('h' para horizontal, 'v' para vertical).
 */
void	calculate_intercept(t_player *player, t_rays ray, t_hit *hit, char dir)
{
	float	diff;

	if (dir == 'h')
	{
		hit->intercept[1] = floor(player->y / 64) * 64;
		if (ray.vy)
			hit->intercept[1] += 64;
		if (ray.vx)
			hit->intercept[1] -= 0.0001;
		diff = hit->intercept[1] - player->y;
		hit->intercept[0] = player->x + (diff) / tan(ray.angle);
	}
	else if (dir == 'v')
	{
		hit->intercept[0] = floor(player->x / 64) * 64;
		if (ray.hx)
			hit->intercept[0] += 64;
		if (ray.hy)
			hit->intercept[0] -= 0.0001;
		diff = hit->intercept[0] - player->x;
		hit->intercept[1] = player->y + (diff) * tan(ray.angle);
	}
}

/**
 * @brief Calcula os passos necessários para avançar verticalmente ou horizontalmente.
 *
 * Esta função calcula os passos necessários para avançar verticalmente ou horizontalmente
 * com base no ângulo do raio e na direção fornecida. Os resultados são armazenados na
 * estrutura `t_hit`.
 *
 * @param ray Estrutura que representa o raio.
 * @param hit Estrutura `t_hit` para armazenar os resultados dos passos.
 * @param direction Caractere que indica a direção ('h' para horizontal, 'v' para vertical).
 */
void	calculate_steps(t_rays ray, t_hit *hit, char direction)
{
	if (direction == 'h')
	{
		hit->step[1] = 64;
		if (ray.vx)
			hit->step[1] *= -1;
		hit->step[0] = 64 / tan(ray.angle);
		if ((ray.hy && hit->step[0] > 0)
			|| (ray.hx && hit->step[0] < 0))
			hit->step[0] *= -1;
	} 
	else if (direction == 'v')
	{
		hit->step[0] = 64;
		if (ray.hy)
			hit->step[0] *= -1;
		hit->step[1] = 64 * tan(ray.angle);
		if ((ray.vx && hit->step[1] > 0)
			|| (ray.vy && hit->step[1] < 0))
			hit->step[1] *= -1;
	}
}

/**
 * @brief Verifica a colisão de um raio com as paredes do mapa.
 *
 * Esta função verifica se há colisão de um raio com as paredes do mapa. Utiliza
 * as coordenadas do raio, a estrutura `t_hit` para armazenar os resultados e a
 * direção da verificação ('h' para horizontal, 'v' para vertical).
 *
 * @param map Ponteiro para a estrutura que representa o mapa.
 * @param ray Estrutura que representa o raio.
 * @param hit Estrutura `t_hit` para armazenar os resultados da verificação.
 * @param direction Direção da verificação ('h' para horizontal, 'v' para vertical).
 * @return 1 se houve colisão, 0 caso contrário.
 */
static int check_collision(t_map *map, t_rays ray, t_hit *hit, char direction)
{
	float coords[2];

	coords[0] = hit->hit_x;
	coords[1] = hit->hit_y;
	if ((ray.vx && direction == 'h') 
		|| (ray.hy 
		&& ray.vy && direction == 'v'))
		coords[1] -= 1;
	return (verify_coords_elements(map, coords[0], coords[1], 1));
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
 * @param map Ponteiro para a estrutura que representa o mapa.
 * @param ray Estrutura que representa o raio.
 * @param hit Estrutura `t_hit` para armazenar os resultados da intercepção vertical.
 * @param direction Direção do movimento ('v' para vertical, 'h' para horizontal).
 */
void increment_position(t_map *map, t_rays ray, t_hit *hit, char direction)
{
	hit->hitted = 0;
	hit->hit_x = hit->intercept[0];
	hit->hit_y = hit->intercept[1];
	while (hit->hit_x >= 0 && hit->hit_y < map->y && 
		((hit->hit_x < map->x && hit->hit_y >= 0 && direction == 'v')
		|| (hit->hit_x <= map->x && hit->hit_y > 0 && direction == 'h')))
	{
		if (check_collision(map, ray, hit, direction))
		{
			hit->hitted = 1;
			return ;
		}
		else
		{
			hit->hit_x += hit->step[0];
			hit->hit_y += hit->step[1];
		}
	}
	hit->hit_x = 0;
	hit->hit_y = 0;
}
