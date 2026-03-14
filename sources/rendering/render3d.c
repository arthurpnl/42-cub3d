/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:10:00 by skoudad           #+#    #+#             */
/*   Updated: 2026/02/21 13:27:00 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Calcule la position fractionnaire du rayon sur le bord du mur
** (0.0 a 1.0), pour l'echantillonnage horizontal de la texture.
*/
static float	calc_wall_x(t_ray *ray, t_data *data)
{
	float	wall_x;

	if (ray->side == 0)
		wall_x = data->player.y + ray->wall_dist * ray->dir_y;
	else
		wall_x = data->player.x + ray->wall_dist * ray->dir_x;
	wall_x -= (int)wall_x;
	return (wall_x);
}

/*
** Lit la couleur d'un pixel dans la texture en (tx, ty).
** Retourne 0 si hors limites.
*/
static int	get_tex_color(t_img *tex, int tx, int ty)
{
	char	*pixel;

	if (tx < 0 || tx >= tex->tex_w || ty < 0 || ty >= tex->tex_h)
		return (0);
	pixel = tex->addr + (ty * tex->line_length
			+ tx * (tex->bits_per_pixel / 8));
	return (*(int *)pixel);
}

/*
** Dessine plafond (0 a start), mur texture (start a end)
** et sol (end a WIN_HEIGHT) pour la colonne col->col_x.
*/
static void	draw_wall_strip(t_data *data, t_col *col)
{
	int	y;
	int	wall_top;

	wall_top = -col->h / 2 + WIN_HEIGHT / 2;
	y = 0;
	while (y < col->start)
		my_mlx_pixel_put(&data->img, col->x, y++,
			color_to_int(data->ceiling));
	while (y < col->end)
	{
		if (col->tex && col->tex->addr && col->tex->tex_h > 0)
			my_mlx_pixel_put(&data->img, col->x, y,
				get_tex_color(col->tex, col->tex_x,
					(y - wall_top) * col->tex->tex_h / col->h));
		y++;
	}
	while (y < WIN_HEIGHT)
		my_mlx_pixel_put(&data->img, col->x, y++,
			color_to_int(data->floor));
}

/*
** Calcule les parametres de la colonne et appelle draw_wall_strip.
*/
static void	draw_tex_col(t_data *data, int x, t_ray *ray, float perp)
{
	t_col	col;

	col.x = x;
	col.h = (int)(WIN_HEIGHT / perp);
	if (col.h <= 0)
		col.h = 1;
	col.start = -col.h / 2 + WIN_HEIGHT / 2;
	col.end = col.h / 2 + WIN_HEIGHT / 2;
	if (col.start < 0)
		col.start = 0;
	if (col.end > WIN_HEIGHT)
		col.end = WIN_HEIGHT;
	if (ray->side == 0 && ray->step_x > 0)
		col.tex = &data->tex[W];
	else if (ray->side == 0)
		col.tex = &data->tex[E];
	else if (ray->step_y > 0)
		col.tex = &data->tex[N];
	else
		col.tex = &data->tex[S];
	col.tex_x = (int)(calc_wall_x(ray, data) * col.tex->tex_w);
	draw_wall_strip(data, &col);
}

/*
** Rendu 3D : cast un rayon par colonne, corrige le fish-eye,
** dessine la colonne texturee avec plafond et sol.
*/
void	render_3d(t_data *data)
{
	int		x;
	float	col_start;
	float	angle;
	t_ray	ray;
	float	perp;

	col_start = data->player.orientation - (FOV * PI / 180.0) / 2.0;
	x = 0;
	while (x < WIN_WIDTH)
	{
		angle = col_start + x * (FOV * PI / 180.0) / WIN_WIDTH;
		cast_ray(data, angle, &ray);
		perp = ray.wall_dist * ft_cos(angle - data->player.orientation);
		if (perp < 0.01)
			perp = 0.01;
		draw_tex_col(data, x, &ray, perp);
		x++;
	}
}
