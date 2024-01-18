/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/18 02:02:30 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/**
** Desenha os raios no mapa. Para cada raio, converte as coordenadas iniciais e de impacto
** para as coordenadas do mapa, e desenha uma linha entre esses pontos na imagem.
**
** @param game: Estrutura principal do jogo.
** @param rays: Estrutura contendo informações sobre os raios.
** 
** Nota: Esta função utiliza a função draw_line.
*/
// void	draw_rays(t_game *game, t_rays *rays)
// {
// 	t_pos	test;
// 	t_pos	hit_test;
// 	int		col;

// 	col = 0;
// 	while (col < game->nbr_rays)
// 	{
// 		test.x = floor(rays[col].rx * 0.2);
// 		test.y = floor(rays[col].ry * 0.2);
// 		hit_test.x = floor(rays[col].hit_x * 0.2);
// 		hit_test.y = floor(rays[col].hit_y * 0.2);
// 		draw_row(&game->img, test, hit_test, COLOR_WHITE);
// 		col++;
// 	}
// }

static void	draw_ray_segment(t_game *game, t_rays ray)
{
	t_coords	coords_ray;
	t_coords	ray_hit;

	coords_ray.x = floor(ray.rx * 0.2);
	coords_ray.y = floor(ray.ry * 0.2);
	ray_hit.x = floor(ray.hit_x * 0.2);
	ray_hit.y = floor(ray.hit_y * 0.2);
	draw_row(&game->img, coords_ray, ray_hit, COLOR_WHITE);
}

void	draw_rays(t_game *game, t_rays *rays)
{
	int	col;

	col = 0;
	while (col < game->num_rays)
	{
		draw_ray_segment(game, rays[col]);
		col++;
	}
}


/**
** Desenha um círculo na imagem especificada com o centro em (xc, yc) e raio r.
** A cor do círculo é definida como COLOR_RED.
** 
** @param image: ponteiro para a estrutura de imagem onde o círculo será desenhado.
** @param xc: coordenada x do centro do círculo.
** @param yc: coordenada y do centro do círculo.
** @param r: raio do círculo.
*/
// void	draw_circle(t_image *image, int xc, int yc, int r)
// {
// 	int	x;
// 	int	y;

// 	x = xc - r;
// 	y = yc - r;
// 	paint_img(image, xc, yc, COLOR_RED);
// 	while (x <= xc + r)
// 	{
// 		y = yc - r;
// 		while (y <= yc + r)
// 		{
// 			if ((x - xc) * (x - xc) + (y - yc) * (y - yc) < r * r)
// 				paint_img(image, x, y, COLOR_RED);
// 			y++;
// 		}
// 		x++;
// 	}
// }

/**
** Desenha o minimapa, representando as paredes e o chão.
** Utiliza a função draw_square para desenhar os elementos do minimapa.
**
* @param game: Estrutura principal do jogo.
* @param map: Estrutura contendo informações do mapa.
*/
// void	draw_mini_map(t_game *game, t_map *map)
// {
// 	t_coords	map_pos;
// 	t_coords	mini_pos;
// 	int			sq_size;

// 	map_pos.y = 0;
// 	sq_size = 64 * 0.2;
// 	while (map_pos.y < map->y)
// 	{
// 		map_pos.x = 0;
// 		while (map_pos.x < map->x)
// 		{
// 			mini_pos.x = map_pos.x * 0.2;
// 			mini_pos.y = map_pos.y * 0.2;
// 			if (verify_coords_elements(game->map, map_pos.x, map_pos.y, 1))
// 				draw_square(&game->img, mini_pos, sq_size, COLOR_DARK_GRAY);
// 			else if (verify_coords_elements(game->map, map_pos.x, map_pos.y, 0))
// 				draw_square(&game->img, mini_pos, sq_size, COLOR_MEDIUM_GRAY);
// 			map_pos.x += 64;
// 		}
// 		map_pos.y += 64;
// 	}
// 	draw_player(game);
// }
