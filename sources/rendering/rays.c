/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 01:36:00 by skoudad           #+#    #+#             */
/*   Updated: 2026/02/21 13:10:00 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Initialise les parametres de Bresenham : deltas et directions.
*/
static void	init_line(t_point a, t_point b, t_point *d, t_point *s)
{
	if (a.x < b.x)
		s->x = 1;
	else
		s->x = -1;
	if (a.y < b.y)
		s->y = 1;
	else
		s->y = -1;
	d->x = ft_abs(b.x - a.x);
	d->y = ft_abs(b.y - a.y);
}

/*
** Trace une ligne de a vers b avec Bresenham.
*/
void	draw_line(t_img *img, t_point a, t_point b, int color)
{
	t_point	d;
	t_point	s;
	int		err;
	int		e2;

	init_line(a, b, &d, &s);
	err = d.x - d.y;
	while (1)
	{
		my_mlx_pixel_put(img, a.x, a.y, color);
		if (a.x == b.x && a.y == b.y)
			break ;
		e2 = 2 * err;
		if (e2 > -d.y)
		{
			err -= d.y;
			a.x += s.x;
		}
		if (e2 < d.x)
		{
			err += d.x;
			a.y += s.y;
		}
	}
}

/*
** Retourne la couleur selon la face du mur touchee.
*/
static int	get_ray_color(t_ray *ray)
{
	if (ray->side == 0 && ray->step_x > 0)
		return (COLOR_WEST);
	if (ray->side == 0)
		return (COLOR_EAST);
	if (ray->step_y > 0)
		return (COLOR_NORTH);
	return (COLOR_SOUTH);
}

/*
** Convertit un point d'impact en coordonnees minimap.
** Si le point depasse le cercle, le clippe au bord.
*/
static t_point	to_minimap(t_data *data, t_point hit)
{
	t_point	mm;
	int		dx;
	int		dy;
	float	len;

	mm.x = MMAP_CX + (hit.x - (int)(data->player.x * TILE_SIZE))
		* MMAP_S / TILE_SIZE;
	mm.y = MMAP_CY + (hit.y - (int)(data->player.y * TILE_SIZE))
		* MMAP_S / TILE_SIZE;
	dx = mm.x - MMAP_CX;
	dy = mm.y - MMAP_CY;
	len = ft_sqrt(dx * dx + dy * dy);
	if (len > MMAP_R - 3)
	{
		mm.x = MMAP_CX + (int)(dx * (MMAP_R - 3) / len);
		mm.y = MMAP_CY + (int)(dy * (MMAP_R - 3) / len);
	}
	return (mm);
}

/*
** Dessine WIN_WIDTH rayons sur la minimap depuis le centre.
** Chaque rayon est clippe au cercle de la minimap.
*/
void	draw_rays(t_data *data)
{
	int		i;
	float	start;
	t_point	origin;
	t_point	hit;
	t_ray	ray;

	start = data->player.orientation - (FOV * PI / 180.0) / 2.0;
	origin.x = MMAP_CX;
	origin.y = MMAP_CY;
	i = 0;
	while (i < WIN_WIDTH)
	{
		hit = cast_ray(data,
				start + i * (FOV * PI / 180.0) / WIN_WIDTH, &ray);
		draw_line(&data->img, origin,
			to_minimap(data, hit), get_ray_color(&ray));
		i++;
	}
}
