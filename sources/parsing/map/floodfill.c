/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:41:58 by skoudad           #+#    #+#             */
/*   Updated: 2026/02/14 17:14:57 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// la map est une copie
// return: 0 ou 1
int	flood_fill(char **map, int x, int y)
{
	if (x < 0 || x >= (int)ft_strlen(map[y]))
		return (1);
	if (y < 0 || y >= ft_strslen(map))
		return (1);
	if (map[y][x] == '1' || map[y][x] == 'A')
		return (0);
	map[y][x] = 'A';
	return (flood_fill(map, x - 1, y) || flood_fill(map, x + 1, y)
		|| flood_fill(map, x, y - 1) || flood_fill(map, x, y + 1));
}
