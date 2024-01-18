/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_validation_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:10:23 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/17 21:14:14 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/**
** Verifica se as texturas e as configurações de teto e chão foram fornecidas.
** Retorna 0 se todas as texturas e configurações são válidas, exibindo mensagens de erro caso contrário.
** 
* @param input: estrutura contendo as informações de entrada do programa.
** 
** Nota: Esta função depende dos campos da estrutura t_config, como has_we, has_ea, has_no, has_so, has_c e has_f.
*/
int	verify_textures(t_config *input)
{
	if (!input->tex.west || !input->tex.east 
		|| !input->tex.north || !input->tex.south)
		return (print_error(INVALID_TEX));
	return (0);
}

/**
** Manipula a textura, copiando a string trimada e atribuindo-a ao ponteiro path.
**
** @param dir: string trimada a ser duplicada.
** @param flag: ponteiro para flag que será configurada para 1.
** @param path: ponteiro para char que receberá a duplicata da string trimada.
** 
** Nota: Esta função utiliza a função ft_strdup da biblioteca personalizada.
*/
static void handle_texture(char *dir, int *flag, char **path)
{
	*flag = 1;
	*path = ft_strdup(dir);
}

/**
** Manipula a textura especificada, atualizando as informações no struct t_config.
**
* @param arg: ponteiro para a estrutura t_config que armazena as informações do jogo.
* @param dir: string contendo a informação da textura, sem espaços extras.
* @param texture: string contendo o identificador da textura ("NO ", "SO ", "WE ", "EA ").
** 
** Nota: Esta função utiliza a função handle_texture.
*/
static void handle_textures(t_config *arg, char *dir, char *texture)
{
	if (ft_strncmp(texture, "NO ", 3) == 0)
		handle_texture(dir, &(arg->tex.north), &(arg->tex.north_path));
	else if (ft_strncmp(texture, "SO ", 3) == 0)
		handle_texture(dir, &(arg->tex.south), &(arg->tex.south_path));
	else if (ft_strncmp(texture, "WE ", 3) == 0)
		handle_texture(dir, &(arg->tex.west), &(arg->tex.west_path));
	else if (ft_strncmp(texture, "EA ", 3) == 0)
		handle_texture(dir, &(arg->tex.east), &(arg->tex.east_path));
}

/**
** Verifica se a linha fornecida contém a textura especificada.
** Retorna 0 se a textura é válida, exibe uma mensagem de erro e retorna -1 caso contrário.
** 
* @param line: linha a ser verificada.
* @param arg: ponteiro para a estrutura t_config contendo as informações de entrada.
* @param texture: string representando a textura a ser verificada.
* @param has_flag: ponteiro para a flag indicando se a textura já foi encontrada.
** 
** Nota: Esta função utiliza as funções ft_strncmp, remove_whitespaces, check_extension,
**       check_xpm_file e handle_textures.
*/
int	has_texture(char *line, t_config *arg, char *texture, int *has_flag)
{
	char	*clean_line;
	int		fd;

	if (!ft_strncmp(line, texture, 3))
	{
		if (*has_flag)
			return (print_error(INVALID_TEX));
		clean_line = remove_whitespaces(line + 2);
		if (ft_strncmp(clean_line + (ft_strlen(clean_line) - 4), XPM_EXTENSION, 4))
		{
			free(clean_line);
			return (print_error(INVALID_TEX));
		}
		fd = verify_xpm_file(clean_line);
		handle_textures(arg, clean_line, texture);
		free(clean_line);
		if (fd < 0)
			return (print_error(INVALID_TEX));
		close(fd);
	}
	return (0);
}
