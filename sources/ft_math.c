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

// ramene l'angle dans [-PI, PI] avant de developper la serie
static float	ft_normalize_angle(float angle)
{
	while (angle > PI)
		angle -= 2 * PI;
	while (angle < -PI)
		angle += 2 * PI;
	return (angle);
}

// serie de Taylor de sin a 10 termes (on n'a pas le droit a math.h)
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
