/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 01:36:00 by skoudad           #+#    #+#             */
/*   Updated: 2026/02/21 13:03:00 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Retourne la couleur d'une position en coordonnees map (wx, wy).
** '1' = mur blanc, ' ' ou hors limites = vide sombre, autre = sol gris.
*/
static int	get_map_color(t_data *data, float wx, float wy)
{
	int	mx;
	int	my;

	mx = (int)wx;
	my = (int)wy;
	if (mx < 0 || my < 0 || my >= data->map_h)
		return (0x111111);
	if (mx >= (int)ft_strlen(data->map[my]))
		return (0x111111);
	if (data->map[my][mx] == '1')
		return (WALL_COLOR);
	if (data->map[my][mx] == ' ')
		return (0x111111);
	return (FLOOR_COLOR_2D);
}

/*
** Dessine un pixel de la minimap. Si le pixel est sur le bord
** du cercle (distance >= R-2), dessine la bordure grise.
** Sinon, convertit la position relative en coordonnees map
** et dessine la couleur correspondante.
*/
static void	draw_mm_pixel(t_data *data, int dx, int dy, int dist)
{
	float	wx;
	float	wy;

	if (dist >= (MMAP_R - 2) * (MMAP_R - 2))
	{
		my_mlx_pixel_put(&data->img, MMAP_CX + dx,
			MMAP_CY + dy, 0xCCCCCC);
		return ;
	}
	wx = data->player.x + (float)dx / MMAP_S;
	wy = data->player.y + (float)dy / MMAP_S;
	my_mlx_pixel_put(&data->img, MMAP_CX + dx,
		MMAP_CY + dy, get_map_color(data, wx, wy));
}

/*
** Dessine la minimap circulaire centree sur le joueur.
** Parcourt tous les pixels dans le carre englobant du cercle,
** ne dessine que ceux a l'interieur du rayon MMAP_R.
** Le contenu de la map deplace autour de la position du joueur.
*/
void	draw_minimap(t_data *data)
{
	int	dx;
	int	dy;
	int	dist;

	dy = -MMAP_R;
	while (dy <= MMAP_R)
	{
		dx = -MMAP_R;
		while (dx <= MMAP_R)
		{
			dist = dx * dx + dy * dy;
			if (dist <= MMAP_R * MMAP_R)
				draw_mm_pixel(data, dx, dy, dist);
			dx++;
		}
		dy++;
	}
}

/*
** Dessine le joueur au centre de la minimap sous forme
** d'un carre rouge de 7x7 pixels (position fixe).
*/
void	draw_player(t_data *data)
{
	int	px;
	int	py;

	py = -3;
	while (py <= 3)
	{
		px = -3;
		while (px <= 3)
		{
			my_mlx_pixel_put(&data->img, MMAP_CX + px,
				MMAP_CY + py, PLAYER_COLOR);
			px++;
		}
		py++;
	}
}
