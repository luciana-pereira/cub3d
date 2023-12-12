/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:03:18 by lucperei          #+#    #+#             */
/*   Updated: 2023/12/09 20:38:49 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	verify_command_line_arg(int argc, char **argv)
{
	error(INVALID_ARG, NULL, NULL, argc != 2);
	// if (!ft_strncmp(argv[1], "-h", 3) || !ft_strncmp(argv[1], "--help", 7))
	// 	usage_error_message(0);
}

static void	verify_file_existence(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	close(fd);
	error(INVALID_FILE, NULL, filename, fd < 0);
	if (str_reverse_compare(".cub", filename, 4))
		error(INVALID_EXT, NULL, NULL, 1);
}

void	verify_map(int argc, char **argv)
{
	verify_command_line_arg(argc, argv);
	verify_file_existence(argv[1]);
}
