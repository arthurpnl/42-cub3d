/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:04:00 by skoudad           #+#    #+#             */
/*   Updated: 2026/02/21 15:04:00 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Verifie si la position (x, y) est un mur ou hors limites.
** Retourne 1 si mur ('1'), espace (' '), ou hors map.
** Retourne 0 si la position est libre.
*/
static int	is_wall(t_data *data, float x, float y)
{
	int	mx;
	int	my;

	mx = (int)x;
	my = (int)y;
	if (mx < 0 || my < 0 || my >= data->map_h)
		return (1);
	if (mx >= (int)ft_strlen(data->map[my]))
		return (1);
	if (data->map[my][mx] == '1' || data->map[my][mx] == ' ')
		return (1);
	return (0);
}

/*
** Version bonus : deplace vers l'avant avec collision sliding.
** Verifie X et Y independamment pour permettre le glissement.
*/
void	move_forward(t_data *data)
{
	float	new_x;
	float	new_y;

	new_x = data->player.x + ft_cos(data->player.orientation) * MOVE_SPEED;
	new_y = data->player.y + ft_sin(data->player.orientation) * MOVE_SPEED;
	if (!is_wall(data, new_x, data->player.y))
		data->player.x = new_x;
	if (!is_wall(data, data->player.x, new_y))
		data->player.y = new_y;
}

/*
** Version bonus : deplace vers l'arriere avec collision sliding.
*/
void	move_backward(t_data *data)
{
	float	new_x;
	float	new_y;

	new_x = data->player.x - ft_cos(data->player.orientation) * MOVE_SPEED;
	new_y = data->player.y - ft_sin(data->player.orientation) * MOVE_SPEED;
	if (!is_wall(data, new_x, data->player.y))
		data->player.x = new_x;
	if (!is_wall(data, data->player.x, new_y))
		data->player.y = new_y;
}

/*
** Modifie l'orientation du joueur de direction * ROT_SPEED radians.
*/
void	rotate_player(t_data *data, int direction)
{
	data->player.orientation += direction * ROT_SPEED;
}

/*
** Appelee a chaque frame, check les touches et applique le mouvement.
*/
void	update_movement(t_data *data)
{
	if (data->keys.forward)
		move_forward(data);
	if (data->keys.backward)
		move_backward(data);
	if (data->keys.rot_left)
		rotate_player(data, -1);
	if (data->keys.rot_right)
		rotate_player(data, 1);
}
