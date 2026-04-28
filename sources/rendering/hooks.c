/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:24:00 by skoudad           #+#    #+#             */
/*   Updated: 2026/02/21 02:19:00 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_rendering(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (data->tex[i].img)
			mlx_destroy_image(data->mlx, data->tex[i].img);
		i++;
	}
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}

int	close_window(t_data *data)
{
	free_rendering(data);
	free_parsing(data);
	exit(0);
	return (0);
}

int	handle_key(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		close_window(data);
	else if (keycode == KEY_W || keycode == KEY_Z)
		data->keys.forward = 1;
	else if (keycode == KEY_S)
		data->keys.backward = 1;
	else if (keycode == KEY_A || keycode == KEY_Q)
		data->keys.strafe_left = 1;
	else if (keycode == KEY_D)
		data->keys.strafe_right = 1;
	else if (keycode == KEY_LEFT)
		data->keys.rot_left = 1;
	else if (keycode == KEY_RIGHT)
		data->keys.rot_right = 1;
	return (0);
}

int	handle_keyrelease(int keycode, t_data *data)
{
	if (keycode == KEY_W || keycode == KEY_Z)
		data->keys.forward = 0;
	else if (keycode == KEY_S)
		data->keys.backward = 0;
	else if (keycode == KEY_A || keycode == KEY_Q)
		data->keys.strafe_left = 0;
	else if (keycode == KEY_D)
		data->keys.strafe_right = 0;
	else if (keycode == KEY_LEFT)
		data->keys.rot_left = 0;
	else if (keycode == KEY_RIGHT)
		data->keys.rot_right = 0;
	return (0);
}
