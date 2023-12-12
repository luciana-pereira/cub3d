/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:03:18 by lucperei          #+#    #+#             */
/*   Updated: 2023/12/09 19:38:53 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	error_message(t_error error)
{
    // Validação e mensagem de erro para cada situação, arquivo de validação -> Parte mandatoria
	write(2, ERROR_CUB3D, 7 * (error != END));
	if (error == INVALID_ARG)
		write(2, ERROR_INVALID_ARG, 28);
	else if (error == INVALID_PWD)
		write(2, ERROR_INVALID_PWD, 47);
	else if (error == INVALID_EXT)
		write(2, ERROR_INVALID_EXT, 26);
	else if (error == INVALID_FILE)
		write(2, ERROR_INVALID_FILE, 20);
	else if (error == EMPTY_FILE)
		write(2, ERROR_EMPTY_FILE, 14);
	else if (error == NO_MEMORY)
		write(2, ERROR_NO_MEMORY, 21);
	else if (error == INVALID_COLOR)
		write(2, ERROR_INVALID_COLOR, 28);
	else if (error == INVALID_WALL)
		write(2, ERROR_INVALID_WALL, 30);
	else if (error == INVALID_MAP)
		write(2, ERROR_INVALID_MAP, 26);
	else if (error == INVALID_CHARAC)
		write(2, ERROR_INVALID_CHARAC, 18);
	else if (error == INVALID_TEX)
		write(2, ERROR_INVALID_TEX, 21);
	else if (error == INVALID_PLAYER)
		write(2, ERROR_INVALID_PLAYER, 26);
}

void	usage_error_message(int status)
{
    write(1, "Usage: ./game <map_file.cub>\n", 29);
	exit(status);
}

void	invalid_argument(t_error error)
{
	if (error == INVALID_ARG)
		usage_error_message(1);
	if (error == END)
		exit(0);
	exit(1);
}

int	error(t_error error, t_game *game, char *str, int control)
{
	if (!control)
		return (0);
	free_game_memory(game);
	error_message(error);
	ft_putendl_fd(str, 2);
	invalid_argument(error);
	return (1);
}
