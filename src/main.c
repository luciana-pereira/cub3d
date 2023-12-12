/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2023/12/10 03:00:26 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// void draw_line(t_game *game, int x, double ray_dir_x, double ray_dir_y)
// {
//     // Desenhar a parede com base no algoritmo de Ray-Casting
//     // A função irá desenhar uma linha vertical representando uma parede
//     // Chamaremos função externa para colocar a textura
// }

// Quebrar função e melhorar logica para o calculo e criar structs t_ray
void draw_map(t_game *game)
{
    int x;

    x = 0;
    while (x < WIDTH)
    {
		int		step_x;
		int		step_y;
		int		map_x;
		int		map_y;
		double	camera_x;
		double	ray_dir_x;
		double	ray_dir_y;
		double	delta_dist_x;
		double	delta_dist_y;
        // Calcula a direção do raio e os valores iniciais do raio
        camera_x = 2 * x / (double)WIDTH - 1;
        ray_dir_x = game->player_dir_x + game->plane_x * camera_x;
        ray_dir_y = game->player_dir_y + game->plane_y * camera_x;
        // Definir as posições no mapa
        map_x = (int)game->player_x;
        map_y = (int)game->player_y;
        // Distâncias Delta para calcular o 
        delta_dist_x = fabs(1 / ray_dir_x);
        delta_dist_y = fabs(1 / ray_dir_y);
        if (ray_dir_x < 0)
        {
            step_x = -1;
            delta_dist_x *= (game->player_x - map_x);
        }
        else
        {
            step_x = 1;
            delta_dist_x *= (map_x + 1.0 - game->player_x);
        }
        if (ray_dir_y < 0)
        {
            step_y = -1;
            delta_dist_y *= (game->player_y - map_y);
        }
        else
        {
            step_y = 1;
            delta_dist_y *= (map_y + 1.0 - game->player_y);
        }
        // Executar DDA
        int hit = 0;
        while (!hit)
        {
            // Realizar a etapa de DDA funções da biblioteca math.h
            // Criar validação para Verifique se o raio bateu em uma parede
            // Quando atinge a parede, calculamos a altura da parede e desenhamos a linha
        }

        x++;
    }
}

int key_press(int keycode, t_game *game)
{
	// Pegar eventos de teclado
	// Função sera quebrada para passar eventos para a função de atualização -> update_player(game, key);
	// O  update_player atualizara a posição do jogador com base na tecla pressionada e tirara a responsabilidade da função
    if (keycode == KEY_W) // W key
    {
        // Atualizar a posição do jogador para avançar
        game->player_x += game->player_dir_x * 0.1;
        game->player_y += game->player_dir_y * 0.1;
    }
    else if (keycode == KEY_A) // A key
    {
        // Atualizar a posição do jogador para mover para a esquerda
        game->player_x -= game->plane_x * 0.1;
        game->player_y -= game->plane_y * 0.1;
    }
    else if (keycode == KEY_S) // S key
    {
        // Atualizar a posição do jogador para retroceder
        game->player_x -= game->player_dir_x * 0.1;
        game->player_y -= game->player_dir_y * 0.1;
    }
    else if (keycode == KEY_D) // D key
    {
        // Atualizar a posição do jogador para se mover para a direita
        game->player_x += game->plane_x * 0.1;
        game->player_y += game->plane_y * 0.1;
    }
    else if (keycode == KEY_ESC) // Esc key
    {
        // Sair do jogo e colocar função para liberar recursos
        exit(0);
    }
    // Limpa e redesenha a janela
	mlx_clear_window(game->mlx, game->win);
	draw_map(game);
	draw_rectangle(game, game->player_x, game->player_y, 0xFF0000);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	// Melhorar tratamento de erro
	verify_map_file(argc, argv);
	// if (argc != 2)
	// {
	// 		write(1, "Usage: ./game path_to_map\n", 26);
	// 		return (1);
	// }
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "Cub3d");
	game.player_x = 2;
	game.player_y = 2;
	game.player_dir_x = 1;
	game.player_dir_y = 0;
	game.plane_x = 0;
	game.plane_y = 0.66;
	game.map = argv[1]; // Validar mapa antes do carregamento

	// Criar definição do hooks para key presses eventos do teclado identico ao so_long
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_loop_hook(game.mlx, draw_map, &game);
	mlx_loop(game.mlx);

	return (0);
}
