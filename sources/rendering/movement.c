/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 01:47:00 by skoudad           #+#    #+#             */
/*   Updated: 2026/02/21 15:04:00 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Version sans bonus : pas de collision.
** Verifie si la position (x, y) est un mur (jamais appele en
** mode mandatory, garde uniquement pour eviter un warning).
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
** Deplace le joueur vers l'avant sans collision.
*/
void	move_forward(t_data *data)
{
	data->player.x += ft_cos(data->player.orientation) * MOVE_SPEED;
	data->player.y += ft_sin(data->player.orientation) * MOVE_SPEED;
	(void)is_wall;
}

/*
** Deplace le joueur vers l'arriere sans collision.
*/
void	move_backward(t_data *data)
{
	data->player.x -= ft_cos(data->player.orientation) * MOVE_SPEED;
	data->player.y -= ft_sin(data->player.orientation) * MOVE_SPEED;
	(void)is_wall;
}

/*
** Modifie l'orientation du joueur de direction * ROT_SPEED radians.
** direction = -1 pour tourner a gauche, 1 pour tourner a droite.
*/
void	rotate_player(t_data *data, int direction)
{
	data->player.orientation += direction * ROT_SPEED;
}

/*
** Appelee a chaque frame, verifie les touches et applique le mouvement.
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
