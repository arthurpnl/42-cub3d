/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 02:09:00 by skoudad           #+#    #+#             */
/*   Updated: 2026/02/21 13:10:00 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Initialise la direction du rayon et les delta distances.
** delta = distance pour traverser une case en X ou Y.
*/
static void	init_dda(t_ray *ray, t_data *data, float angle)
{
	ray->dir_x = ft_cos(angle);
	ray->dir_y = ft_sin(angle);
	ray->map_x = (int)data->player.x;
	ray->map_y = (int)data->player.y;
	if (ray->dir_x == 0)
		ray->delta_x = 1e30;
	else
		ray->delta_x = 1.0 / (ray->dir_x * ((ray->dir_x > 0) * 2 - 1));
	if (ray->dir_y == 0)
		ray->delta_y = 1e30;
	else
		ray->delta_y = 1.0 / (ray->dir_y * ((ray->dir_y > 0) * 2 - 1));
}

/*
** Initialise step (-1 ou 1) et distances laterales initiales.
*/
static void	init_step(t_ray *ray, t_data *data)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_x = (data->player.x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->map_x + 1.0 - data->player.x) * ray->delta_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_y = (data->player.y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->map_y + 1.0 - data->player.y) * ray->delta_y;
	}
}

/*
** Execute le DDA : avance case par case jusqu'a un mur ou hors map.
** ray->side = 0 si mur vertical touche, 1 si mur horizontal.
*/
static void	run_dda(t_ray *ray, t_data *data)
{
	ray->side = 0;
	while (1)
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0 || ray->map_y >= data->map_h
			|| ray->map_x < 0 || ray->map_x >= data->map_w)
			break ;
		if (!data->map[ray->map_y]
			|| data->map[ray->map_y][ray->map_x] == '\0'
			|| data->map[ray->map_y][ray->map_x] == '1')
			break ;
	}
}

/*
** Calcule le point d'impact exact et la distance perpendiculaire.
** Stocke wall_dist dans ray pour le rendu 3D.
*/
static t_point	get_hit_point(t_ray *ray, t_data *data)
{
	t_point	hit;

	if (ray->side == 0)
		ray->wall_dist = ray->side_x - ray->delta_x;
	else
		ray->wall_dist = ray->side_y - ray->delta_y;
	hit.x = (int)((data->player.x + ray->wall_dist
				* ray->dir_x) * TILE_SIZE);
	hit.y = (int)((data->player.y + ray->wall_dist
				* ray->dir_y) * TILE_SIZE);
	return (hit);
}

/*
** Lance un rayon, remplit ray avec la distance et la face touchee.
** Retourne le point d'impact en pixels.
*/
t_point	cast_ray(t_data *data, float angle, t_ray *ray)
{
	init_dda(ray, data, angle);
	init_step(ray, data);
	run_dda(ray, data);
	return (get_hit_point(ray, data));
}
