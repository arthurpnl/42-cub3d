/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:04:00 by skoudad           #+#    #+#             */
/*   Updated: 2026/02/21 15:04:00 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Place un pixel dans le buffer image avec verification
** des limites de la fenetre.
*/
void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/*
** Version bonus : Applique les mouvements, dessine le rendu 3D
** puis la minimap circulaire avec rayons et joueur par-dessus.
*/
int	render_frame(t_data *data)
{
	update_movement(data);
	render_3d(data);
	draw_minimap(data);
	draw_rays(data);
	draw_player(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}
