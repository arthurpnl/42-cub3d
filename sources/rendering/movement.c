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

// X et Y testes separement -> on glisse le long du mur en diagonale
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

// strafe = perpendiculaire au regard (orientation - PI/2)
// identite : cos(o - PI/2) = sin(o), sin(o - PI/2) = -cos(o)
void	strafe_left(t_data *data)
{
	float	new_x;
	float	new_y;

	new_x = data->player.x + ft_sin(data->player.orientation) * MOVE_SPEED;
	new_y = data->player.y - ft_cos(data->player.orientation) * MOVE_SPEED;
	if (!is_wall(data, new_x, data->player.y))
		data->player.x = new_x;
	if (!is_wall(data, data->player.x, new_y))
		data->player.y = new_y;
}

void	strafe_right(t_data *data)
{
	float	new_x;
	float	new_y;

	new_x = data->player.x - ft_sin(data->player.orientation) * MOVE_SPEED;
	new_y = data->player.y + ft_cos(data->player.orientation) * MOVE_SPEED;
	if (!is_wall(data, new_x, data->player.y))
		data->player.x = new_x;
	if (!is_wall(data, data->player.x, new_y))
		data->player.y = new_y;
}
