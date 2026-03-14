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

/*
** Libere toutes les ressources graphiques de maniere securisee :
** 1. Detruit les 4 textures chargees (si elles existent)
** 2. Detruit l'image buffer
** 3. Detruit la fenetre
** 4. Detruit la connexion X11 et free le pointeur mlx
** Chaque etape verifie que le pointeur n'est pas NULL.
*/
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

/*
** Callback appelee a la fermeture de la fenetre (croix ou ESC).
** Libere les ressources graphiques puis les donnees du parsing,
** et termine le programme avec exit(0). Retourne 0 (jamais atteint).
*/
int	close_window(t_data *data)
{
	free_rendering(data);
	free_parsing(data);
	exit(0);
	return (0);
}

/*
** Callback appelee lors d'un appui sur une touche (KeyPress, event 2).
** Met a 1 le flag correspondant dans data->keys pour permettre
** les mouvements simultanes. ESC appelle close_window directement.
** Retourne toujours 0.
*/
int	handle_key(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		close_window(data);
	else if (keycode == KEY_UP)
		data->keys.forward = 1;
	else if (keycode == KEY_DOWN)
		data->keys.backward = 1;
	else if (keycode == KEY_LEFT)
		data->keys.rot_left = 1;
	else if (keycode == KEY_RIGHT)
		data->keys.rot_right = 1;
	return (0);
}

/*
** Callback appelee lors du relachement d'une touche (KeyRelease, event 3).
** Remet a 0 le flag correspondant dans data->keys pour arreter
** le mouvement associe. Retourne toujours 0.
*/
int	handle_keyrelease(int keycode, t_data *data)
{
	if (keycode == KEY_UP)
		data->keys.forward = 0;
	else if (keycode == KEY_DOWN)
		data->keys.backward = 0;
	else if (keycode == KEY_LEFT)
		data->keys.rot_left = 0;
	else if (keycode == KEY_RIGHT)
		data->keys.rot_right = 0;
	return (0);
}
