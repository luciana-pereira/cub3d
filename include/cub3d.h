/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:37:56 by lucperei          #+#    #+#             */
/*   Updated: 2023/12/11 01:17:59 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>

// Separar structs por includes diferentes
#  define KEY_ESC 53
#  define KEY_W 13
#  define KEY_Q 12
#  define KEY_R 15
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_E 14
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_LEFT 123
#  define KEY_RIGHT 124

// Define para tratamento de erro
# define ERROR_CUB3D "cub3d: "
# define ERROR_INVALID_ARG "Invalid number of arguments\n"
# define ERROR_INVALID_PWD "Programa is not run in the root of the project\n"
# define ERROR_INVALID_EXT "File must be of .cub type\n"
# define ERROR_INVALID_FILE "Error opening file: "
# define ERROR_EMPTY_FILE "File is empty\n"
# define ERROR_NO_MEMORY "Device out of memory\n"
# define ERROR_INVALID_COLOR "Inserted and invalid color\n"
# define ERROR_INVALID_WALL "Map is not surrounded by walls\n"
# define ERROR_INVALID_MAP "Informed and invalid map\n"
# define ERROR_INVALID_CHARAC "Invalid character\n"
# define ERROR_INVALID_TEX "Invalid texture file\n"
# define ERROR_INVALID_PLAYER "Invalid number of players\n"
# define PATH_BLACK "textures/black.xpm"
# define PATH_SCOPE "textures/scope.xpm"

//Minimap e parede
# define COLOR_BLACK 0x00000000
# define COLOR_TRANS 0xFF000000
# define COLOR_RED 0x00FF0000
# define COLOR_GREEN 0x0000FF00
# define COLOR_GRAY 0x005E5C64
# define COLOR_BLUE 0x008BB5F8
# define COLOR_WHITE 0xFFFFFF
# define COLOR_LIGHT_BLUE 0x00BDC1C6 
# define COLOR_GREENISH_YELLOW 0x00FDD663
# define ALPHA_MASK 0xFF

# define WIDTH 800
# define HEIGHT 600
# define MAP_WIDTH 19
# define MAP_HEIGHT 7

//Utilizar o M_PI da biblioteca math.h para representar o  π (pi) no calculo 
//# define DEG_TO_RAD(degree) ((degree) * M_PI / 180)
//# define DEG_TO_RAD(degree) ((degree) * 0.017453292519943295f)
//# define PI_OVER_180 0.017453292519943295
//# define DEG_TO_RAD(degree) ((degree) * PI_OVER_180)
# define FOV_ANGLE (60 * M_PI / 180)

typedef struct s_game
{
	void *mlx;
	void *win;
	double player_x;
	double player_y;
	double player_dir_x;
	double player_dir_y;
	double plane_x;
	double plane_y;
	char **map;
} t_game;



typedef enum s_error
{
	END,
	INVALID_ARG,
	INVALID_PWD,
	INVALID_EXT,
	INVALID_FILE,
	EMPTY_FILE,
	NO_MEMORY,
	INVALID_COLOR,
	INVALID_WALL,
	INVALID_MAP,
	INVALID_CHARAC,
	INVALID_TEX,
	INVALID_PLAYER,
}	t_error;

// | Handle the error
void	error_message(t_error error);
void	usage_error_message(int status);
void	invalid_argument(t_error error);
int		error(t_error error, t_game *game, char *str, int control);

// Verify Map
void	verify_map(int argc, char **argv);

// | Free
void	free_array(char ***array);
void	destroy_image(t_game *game);
void	free_game_memory(t_game *game);

// | Utils
int		str_reverse_compare(const char *str1, const char *str2, size_t n);

// | Main
int		key_press(int keycode, t_game *game);
void	draw_map(t_game *game);

#endif
