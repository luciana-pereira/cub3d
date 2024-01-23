/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:42:09 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/23 12:56:16 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	verify_args(int argc, char **argv)
{
	if (argc != 2)
		return (print_error(INVALID_ARG));
	if (ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), CUB_EXTENSION, 4))
		return (print_error(INVALID_EXT));
	return (0);
}

int	process_input(int argc, char **argv, t_config **input)
{
	if (verify_args(argc, argv) != 0)
		return (-1);
	*input = (t_config *)malloc(sizeof(t_config));
	if (*input == NULL)
		return (-1);
	init_structure(*input);
	init_settings(*input, argv);
	if (*input == NULL)
		return (-1);
	return (0);
}
