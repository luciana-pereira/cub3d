/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:04:30 by luizedua          #+#    #+#             */
/*   Updated: 2024/01/19 17:38:37 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "structs.h"

// | Events
int		key_press(int key, t_game *game);
void	move_player(t_game *game, int walk, int camera_control);

// | Graphics
int		render_frame(t_game *game);
void	load_textures(t_game *game);
void	print_map(t_map *map, int **map_matrix);
void	paint_img(t_image *image, int x, int y, int color);
void	draw_wall(t_game *game, int x, int top_pixel, int bot_pixel);

// | Init
void	init_mlx(t_game	*game);
void	init_mlx_hooks(t_game *game);
void	init_structure(t_config *input);
void	init_map(t_config **input, t_map **map);
void	init_settings(t_config *input, char **argv);
void	init_graph_env(t_map *map, t_player *player);
int		init_game(t_config *input, t_map **map, t_player **player);
int		init_player(t_player **player, int py, int px, char player_dir);

// | Math
float	fix_ang(float angle);
float	radians(float degrees);
int		calc_horizontal_disp(t_rays ray);
float	distance(float x1, float y1, float x2, float y2);
int		calculate_position(t_game *game, int col, int control);
void	scanline_flood_fill(int **duplicate, int x, int y, t_map *map);

// | Parse
int		**copy_map(t_map *map);
int		verify_line(char *str);
t_lst	*remove_empty(t_lst *start);
int		verify_xpm_file(char *path);
int		verify_colors(t_config *input);
int		verify_players(t_config *input);
int		verify_textures(t_config *input);
int		process_color(char **color, int *arg);
int		**allocate_map_memory(t_config **input);
void	load_map(t_config **input, t_map **map);
int		read_and_process_file(t_config **input);
int		is_valid_map_path(t_map *map, int x, int y);
int		map_normalizer(t_lst *map, t_config **input);
int		**create_map(t_lst *start, t_config **input);
int		map_checker(t_lst *prev, t_lst *map, int size);
int		verify_all_elements(char *line, t_config *input);
int		**read_map(int fd, t_config **input, t_lst *node);
int		process_map_line(char *line_map, t_config **input);
int		process_input(int argc, char **argv, t_config **input);
int		verify_map(t_lst *map, t_config **input, int inside_map);
int		get_element(char element, t_config **input, int x, int y);
int		verify_coords_elements(t_map *map, float x, float y, int flag);
int		has_floor_ceiling(char *line, int *arg, char *element, int *flag);
int		get_texture(t_game *game, t_image tex, int coord[2], int invert);
int		has_texture(char *line, t_config *arg, char *texture, int *has_flag);

// | Rays
int		is_facing(float angle, int direction);
void	cast_and_generate_projection(t_game *game);
void	init_ray(t_rays *ray, t_player *player, float angle);
void	calculate_steps(t_rays ray, t_hit *hit, char direction);
void	find_wall(t_hit *h, t_hit *v, t_player *p, float angle);
void	calc_vert_ray_intercept(t_game *game, t_player *player, t_rays *ray);
void	increment_position(t_map *map, t_rays ray, t_hit *hit, char direction);
void	calculate_intercept(t_player *player, t_rays ray, t_hit *hit, char dir);

// | Utils
void	free_game(t_game *game);
int		close_win(t_game *game);
void	free_array(char **array);
void	free_input(t_config *input);
int		is_numeric(const char *str);
char	*remove_whitespaces(const char *str);

int		print_error(char *message);
void	exit_with_error(char *str, t_game *game);
void	if_error(char *str);
void	free_all(t_lst *map_line, t_config *input, int **map);
void	free_map(t_map *map);
void	free_map_lines(t_lst *map_line);
void	free_2d_array(int **matrix, int rows);

#endif
