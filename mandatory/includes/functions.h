#ifndef FUNCTIONS_H
#define FUNCTIONS_H

# include "structs.h"

t_image get_wall_texture(t_game *game, int x, int *invert);
int get_wall_texture_color(t_game *game, int x, int coord[2], int *invert);


// | Events
int		key_press(int key, t_game *game);
void	move_player(t_game *game, int walk, int camera_control);

// | Graphics
int		render_frame(t_game *game);
void	print_map(t_map *map, int **map_matrix);
void	init_graph_env(t_map *map, t_player *player);
void	paint_img(t_image *image, int x, int y, int color);
// void	draw_line(t_image *image, t_pos a, t_pos b, int color);

// | Init
void	init_mlx(t_game	*game);
void	init_mlx_hooks(t_game *game);
void	init_structure(t_config *input);
void	init_map(t_config **input, t_map **map);
void	init_settings(t_config *input, char **argv);
void	init_graph_env(t_map *map, t_player *player);
int		init_game(t_config *input, t_map **map, t_player **player);
int 	init_player(t_player **player, int py, int px, char player_dir);

// | Math
void	flood_fill(int **duplicate, int x, int y, t_map *map);
int		top_bot_pixel(t_game *game, int col, int control);

// | Parse
int		**copy_map(t_map *map);
int		verify_line(char *str);
int		verify_colors(t_config *input);
int		verify_textures(t_config *input);
t_lst	*remove_empty_lines(t_lst *start);
int		process_color(char **color, int *arg);
void	load_map(t_config **input, t_map **map);
int		read_and_process_file(t_config **input);
int		verify_players(t_config *input, int **map);
int		is_valid_map_path(t_map *map, int x, int y);
int		**create_map(t_lst *start, t_config **input);
int		verify_all_elements(char *line, t_config *input);
int		verify_map(t_lst *map, t_config **input, int inside_map);
int		get_element(char element, t_config **input, int x, int y);
int		verify_coords_elements(t_map *map, float x, float y, int flag);
int		has_floor_ceiling(char *line, int *arg, char *element, int *flag);
int		get_texture(t_game *game, t_image texture, int coord[2], int invert);
int		has_texture(char *line, t_config *arg, char *texture, int *has_flag);

// | Utils
void	free_game(t_game *game);
int		close_win(t_game *game);
void	free_array(char **array);
void	free_input(t_config *input);
int		is_numeric(const char *str);
char	*remove_whitespaces(const char *str);
#endif
