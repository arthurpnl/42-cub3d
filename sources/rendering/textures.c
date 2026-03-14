/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:24:00 by skoudad           #+#    #+#             */
/*   Updated: 2026/02/17 16:24:00 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	load_one_texture(t_data *data, int i)
{
	data->tex[i].img = mlx_xpm_file_to_image(data->mlx,
			data->textures[i], &data->tex[i].tex_w, &data->tex[i].tex_h);
	if (!data->tex[i].img)
	{
		ft_error("Failed to load texture");
		return (1);
	}
	data->tex[i].addr = mlx_get_data_addr(data->tex[i].img,
			&data->tex[i].bits_per_pixel, &data->tex[i].line_length,
			&data->tex[i].endian);
	if (!data->tex[i].addr)
	{
		ft_error("Failed to get texture data");
		return (1);
	}
	return (0);
}

int	load_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (load_one_texture(data, i))
			return (1);
		i++;
	}
	return (0);
}

int	color_to_int(t_color color)
{
	return (color.r << 16 | color.g << 8 | color.b);
}
