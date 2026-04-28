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

// delta = distance a parcourir pour traverser une case entiere en X ou Y
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

// avance case par case jusqu'a tomber sur un '1' ou sortir de la map
// side = 0 pour un mur Est/Ouest, 1 pour un mur Nord/Sud
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
			|| ray->map_x >= (int)ft_strlen(data->map[ray->map_y])
			|| data->map[ray->map_y][ray->map_x] == '1')
			break ;
	}
}

// derniere distance parcourue avant de toucher le mur
static void	set_wall_dist(t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_dist = ray->side_x - ray->delta_x;
	else
		ray->wall_dist = ray->side_y - ray->delta_y;
}

void	cast_ray(t_data *data, float angle, t_ray *ray)
{
	init_dda(ray, data, angle);
	init_step(ray, data);
	run_dda(ray, data);
	set_wall_dist(ray);
}
