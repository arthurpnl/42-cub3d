/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:30:00 by skoudad           #+#    #+#             */
/*   Updated: 2026/04/27 23:02:52 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// direction = -1 (gauche) ou 1 (droite)
void	rotate_player(t_data *data, int direction)
{
	data->player.orientation += direction * ROT_SPEED;
}

void	update_movement(t_data *data)
{
	if (data->keys.forward)
		move_forward(data);
	if (data->keys.backward)
		move_backward(data);
	if (data->keys.strafe_left)
		strafe_left(data);
	if (data->keys.strafe_right)
		strafe_right(data);
	if (data->keys.rot_left)
		rotate_player(data, -1);
	if (data->keys.rot_right)
		rotate_player(data, 1);
}
