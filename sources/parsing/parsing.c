/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 00:00:00 by skoudad           #+#    #+#             */
/*   Updated: 2026/02/07 16:50:27 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
		data->textures[i++] = NULL;
	data->ceiling.r = -1;
	data->floor.r = -1;
}

static void	finish_reading(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}

int	parsing(t_data *data, char *path)
{
	int	fd;

	init_data(data);
	if (check_suffix(path, ".cub"))
		return (ft_error("Wrong map extension, expected .cub"), 1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ft_error("Failed to open map file"), 1);
	if (check_texture(data, fd))
		return (finish_reading(fd), close(fd), 1);
	if (check_map(data, fd))
		return (free_textures(data->textures), finish_reading(fd), close(fd)
			, 1);
	close(fd);
	return (0);
}
