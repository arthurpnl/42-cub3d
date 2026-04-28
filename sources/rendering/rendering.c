/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 21:06:21 by skoudad           #+#    #+#             */
/*   Updated: 2026/02/21 02:19:00 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calc_map_size(t_data *data)
{
	int	y;
	int	len;

	data->map_h = 0;
	data->map_w = 0;
	while (data->map[data->map_h])
		data->map_h++;
	y = 0;
	while (y < data->map_h)
	{
		len = ft_strlen(data->map[y]);
		if (len > data->map_w)
			data->map_w = len;
		y++;
	}
}

static int	init_img(t_data *data)
{
	data->img.img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img.img)
		return (1);
	data->img.addr = mlx_get_data_addr(data->img.img,
			&data->img.bits_per_pixel, &data->img.line_length,
			&data->img.endian);
	if (!data->img.addr)
		return (1);
	return (0);
}

static int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (1);
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!data->win)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
		return (1);
	}
	if (init_img(data))
	{
		free_rendering(data);
		return (1);
	}
	return (0);
}

int	rendering(t_data *data)
{
	calc_map_size(data);
	if (init_mlx(data))
		return (1);
	if (load_textures(data))
		return (free_rendering(data), 1);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_hook(data->win, 2, 1L << 0, handle_key, data);
	mlx_hook(data->win, 3, 1L << 1, handle_keyrelease, data);
	mlx_loop_hook(data->mlx, render_frame, data);
	mlx_loop(data->mlx);
	free_rendering(data);
	return (0);
}
