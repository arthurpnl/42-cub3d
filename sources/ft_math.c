/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 01:50:00 by skoudad           #+#    #+#             */
/*   Updated: 2026/02/21 13:10:00 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Normalise un angle en radians dans l'intervalle [-PI, PI]
** pour assurer la convergence des series de Taylor.
*/
static float	ft_normalize_angle(float angle)
{
	while (angle > PI)
		angle -= 2 * PI;
	while (angle < -PI)
		angle += 2 * PI;
	return (angle);
}

/*
** Calcule le sinus de x (en radians) via la serie de Taylor
** a 10 termes. Remplace math.h sin().
*/
float	ft_sin(float x)
{
	float	result;
	float	term;
	int		i;

	x = ft_normalize_angle(x);
	result = 0;
	term = x;
	i = 1;
	while (i <= 10)
	{
		result += term;
		term *= -x * x / ((2 * i) * (2 * i + 1));
		i++;
	}
	return (result);
}

/*
** Calcule le cosinus de x (en radians) via la serie de Taylor
** a 10 termes. Remplace math.h cos().
*/
float	ft_cos(float x)
{
	float	result;
	float	term;
	int		i;

	x = ft_normalize_angle(x);
	result = 0;
	term = 1;
	i = 1;
	while (i <= 10)
	{
		result += term;
		term *= -x * x / ((2 * i - 1) * (2 * i));
		i++;
	}
	return (result);
}

/*
** Retourne la valeur absolue de l'entier n.
*/
int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

/*
** Calcule la racine carree de n par la methode de Newton
** (methode babylonienne). 10 iterations pour une precision
** suffisante. Retourne 0 si n <= 0.
*/
float	ft_sqrt(float n)
{
	float	x;
	int		i;

	if (n <= 0)
		return (0);
	x = n;
	i = 0;
	while (i < 10)
	{
		x = (x + n / x) / 2.0;
		i++;
	}
	return (x);
}
