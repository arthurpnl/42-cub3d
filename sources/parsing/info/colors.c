/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 22:16:55 by skoudad           #+#    #+#             */
/*   Updated: 2026/02/07 15:40:06 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	color_is_numeric(char *color)
{
	int	i;

	i = 0;
	while (color[i])
	{
		if (!ft_isdigit(color[i]))
			return (1);
		i++;
	}
	return (0);
}

int	put_color(t_color *color, char *floorc)
{
	char	**colors;

	if (color->r != -1)
		return (1);
	colors = ft_split(floorc, ',');
	if (ft_strslen(colors) != 3)
		return (free_strs(colors), 1);
	if (ft_atoi(colors[0]) < 0 || ft_atoi(colors[0]) > 255
		|| ft_strlen(colors[0]) >= 4 || ft_atoi(colors[1]) < 0
		|| ft_atoi(colors[1]) > 255 || ft_strlen(colors[1]) >= 4
		|| ft_atoi(colors[2]) < 0 || ft_atoi(colors[2]) > 255
		|| ft_strlen(colors[2]) >= 4 || color_is_numeric(colors[0])
		|| color_is_numeric(colors[1]) || color_is_numeric(colors[2]))
		return (free_strs(colors), 1);
	color->r = ft_atoi(colors[0]);
	color->g = ft_atoi(colors[1]);
	color->b = ft_atoi(colors[2]);
	free_strs(colors);
	return (0);
}
