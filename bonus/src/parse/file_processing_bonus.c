/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/13 21:32:27 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/**
 * @brief Processa as linhas do arquivo de configuração.
 *
 * Esta função é chamada pela função principal `read_and_process_file`. Ela continua lendo e
 * processando linhas do arquivo até que todos os elementos essenciais tenham sido encontrados.
 * Cada linha é processada removendo espaços em branco e verificando os elementos com as funções
 * apropriadas. O loop é interrompido quando todos os elementos essenciais foram identificados.
 *
 * @param input Ponteiro para um ponteiro da estrutura `t_config`.
 * @param line Linha lida do arquivo de configuração.
 */
static void	process_file_lines(t_config **input, char *line)
{
	char	*current_line;

	while (line)
	{
		current_line = remove_whitespaces(line);
		free(line);
		if (!verify_all_elements(current_line, *input))
		{
			free(current_line);
			return ;
		}
		free(current_line);
		if ((*input)->tex.north && (*input)->tex.south
			&& (*input)->tex.east && (*input)->tex.west
			&& (*input)->ceiling && (*input)->floor)
		{
			break ;
		}
		line = get_next_line((*input)->fd);
	}
}

/**
 * @brief Lê e processa o conteúdo de um arquivo de configuração.
 *
 * Esta função realiza a leitura e processamento do conteúdo de um arquivo de configuração
 * representado pela estrutura `t_config`. O arquivo é lido linha por linha usando a função
 * `get_next_line`, e cada linha é processada removendo espaços em branco com `remove_whitespaces`.
 * Em seguida, a função verifica os elementos da linha usando `verify_all_elements`. O processo
 * é repetido até que todos os elementos essenciais sejam encontrados no arquivo. Caso o arquivo
 * esteja vazio, a função imprime um erro e retorna 0, indicando falha. Caso contrário, retorna 1,
 * indicando sucesso.
 *
 * @param input Ponteiro para um ponteiro da estrutura `t_config`.
 * @return 1 em caso de sucesso, 0 em caso de falha.
 */
int	read_and_process_file(t_config **input)
{
	char	*line;

	line = get_next_line((*input)->fd);
	if (line == NULL)
	{
		print_error(EMPTY_FILE);
		return (0);
	}
	process_file_lines(input, line);
	return (1);
}

/**
 * @brief Verifica se um arquivo é um arquivo XPM válido.
 *
 * Esta função recebe o caminho para um arquivo e tenta abrir o arquivo para leitura.
 * Em seguida, lê a primeira linha do arquivo usando `get_next_line` e verifica se a linha
 * começa com o identificador XPM_FILE. Se o arquivo não puder ser aberto ou a linha não
 * corresponder ao identificador, a função fecha o arquivo (se estiver aberto) e retorna -1,
 * indicando uma verificação malsucedida. Caso contrário, retorna o descritor de arquivo (fd)
 * para uso posterior.
 *
 * @param path Caminho para o arquivo XPM.
 * @return Descritor de arquivo (fd) em caso de sucesso, -1 em caso de falha.
 */
int	verify_xpm_file(char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL || ft_strncmp(line, XPM_FILE, 9))
	{
		close (fd);
		return (-1);
	}
	free(line);
	return (fd);
}
