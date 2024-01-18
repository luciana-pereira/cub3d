/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_oper_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 01:45:12 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/18 01:45:19 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/**
 * @brief Normaliza um ângulo para o intervalo [0, 2π).
 *
 * Esta função recebe um valor de ângulo em radianos e normaliza-o para o intervalo [0, 2π).
 * Utiliza a constante `two_pi` para representar 2π e a função `remainder` para calcular o
 * resto da divisão por `two_pi`. Se o ângulo resultante for negativo, adiciona `two_pi` para
 * garantir que esteja no intervalo desejado. O ângulo normalizado é então retornado.
 *
 * @param angle Valor do ângulo em radianos a ser normalizado.
 * @return Ângulo normalizado no intervalo [0, 2π).
 */
float	fix_ang(float angle)
{
	float	two_pi;

	two_pi = M_PI * 2.0f;
	angle = remainder(angle, two_pi);
	if (angle < 0)
		angle += two_pi;
	return (angle);
}

/**
 * @brief Calcula a distância euclidiana entre dois pontos no plano.
 *
 * Esta função recebe as coordenadas de dois pontos (x1, y1) e (x2, y2) e calcula a distância
 * euclidiana entre eles utilizando a fórmula matemática da distância entre dois pontos em um
 * plano bidimensional. A distância é retornada como um valor de ponto flutuante.
 *
 * @param x1 Coordenada x do primeiro ponto.
 * @param y1 Coordenada y do primeiro ponto.
 * @param x2 Coordenada x do segundo ponto.
 * @param y2 Coordenada y do segundo ponto.
 * @return A distância euclidiana entre os dois pontos.
 */
float	distance(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

/**
 * @brief Converte um valor em graus para radianos.
 *
 * Esta função recebe um valor em graus e realiza a conversão para radianos usando a fórmula
 * matemática: radianos = graus * (π / 180). O resultado da conversão é retornado.
 *
 * @param degrees Valor em graus a ser convertido para radianos.
 * @return Valor em radianos correspondente à conversão.
 */
double	radians(double degrees)
{
	return (degrees * M_PI / 180);
}
