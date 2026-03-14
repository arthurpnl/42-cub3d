/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 16:51:28 by skoudad           #+#    #+#             */
/*   Updated: 2026/02/07 16:27:25 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// check qu'on a 1 joueur (N/S/E/W) only et uniquement 0 / 1 / space
int	check_map_content(char **map, t_data *data, int player)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (is_in(map[i][j], "01NESW \f\t\r\v") == -1)
				return (1);
			if (is_in(map[i][j], "NESW") != -1)
			{
				data->player.spawn_orientation = is_in(map[i][j], "NESW");
				data->player.x = (float)j;
				data->player.y = (float)i;
				map[i][j] = '0';
				player++;
			}
			else if (is_in(map[i][j], " \f\t\r\v") != -1)
				map[i][j] = '1';
		}
	}
	return (player != 1);
}

int	check_map_closed(t_data *data)
{
	char	**copy_map;
	int		closed;		

	copy_map = ft_strsdup(data->map);
	if (!copy_map)
		return (1);
	closed = flood_fill(copy_map, data->player.x, data->player.y);
	free_strs(copy_map);
	return (closed);
}

int	check_map_logic(t_data *data)
{
	data->map = map_table(data->beggin);
	if (!data->map)
		return (free_line(data->beggin, true), 1);
	free_line(data->beggin, false);
	if (check_map_content(data->map, data, 0))
		return (ft_error("Map content"), free_strs(data->map), 1);
	if (check_map_closed(data))
		return (ft_error("Map not closed"), free_strs(data->map), 1);
	return (0);
}

int	check_map(t_data *data, int fd)
{
	char	*line;
	t_line	*current_line;
	t_line	*previous_line;

	data->beggin = NULL;
	previous_line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		current_line = fill_line(line);
		if (!current_line)
			return (free_line(data->beggin, true), free(line), 1);
		if (!previous_line)
			data->beggin = current_line;
		if (previous_line)
			previous_line->next = current_line;
		previous_line = current_line;
	}
	return (check_map_logic(data));
}
