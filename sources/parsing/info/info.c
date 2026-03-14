/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 21:06:21 by skoudad           #+#    #+#             */
/*   Updated: 2026/02/14 18:26:14 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_texture_line(t_data *data, char *path_texture, int direction)
{
	char	*path;
	int		fd;

	if (data->textures[direction])
		return (1);
	fd = open(path_texture, O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	path = ft_strdup(path_texture);
	if (!path)
		return (1);
	data->textures[direction] = path;
	return (0);
}

static int	floor_ceiling_logic(t_data *data, char **strs)
{
	if (!ft_strcmp(strs[0], "F"))
	{
		if (put_color(&data->floor, strs[1]))
			return (ft_error("Floor color"), 1);
	}
	else if (!ft_strcmp(strs[0], "C"))
	{
		if (put_color(&data->ceiling, strs[1]))
			return (ft_error("Ceiling color"), 1);
	}
	return (0);
}

static int	texture_logic(t_data *data, char **strs)
{
	if (!ft_strcmp(strs[0], "NO"))
	{
		if (parse_texture_line(data, strs[1], N))
			return (ft_error("Side North parsing"), 1);
	}
	else if (!ft_strcmp(strs[0], "SO"))
	{
		if (parse_texture_line(data, strs[1], S))
			return (ft_error("Side South parsing"), 1);
	}
	else if (!ft_strcmp(strs[0], "EA"))
	{
		if (parse_texture_line(data, strs[1], E))
			return (ft_error("Side East parsing"), 1);
	}
	else if (!ft_strcmp(strs[0], "WE"))
	{
		if (parse_texture_line(data, strs[1], W))
			return (ft_error("Side West parsing"), 1);
	}
	return (0);
}

static int	check_logic(t_data *data, char *line)
{
	char	**strs;

	strs = ft_split_custom(line, " \f\t\n\r\v");
	if (ft_strslen(strs) == 0)
		return (free_strs(strs), 0);
	if (ft_strslen(strs) != 2)
		return (free_strs(strs), ft_error("Too much info"), 1);
	if (!ft_strcmp(strs[0], "NO") || !ft_strcmp(strs[0], "SO")
		|| !ft_strcmp(strs[0], "EA") || !ft_strcmp(strs[0], "WE"))
	{
		if (texture_logic(data, strs))
			return (free_strs(strs), 1);
	}
	else if (!ft_strcmp(strs[0], "F") || !ft_strcmp(strs[0], "C"))
	{
		if (floor_ceiling_logic(data, strs))
			return (free_strs(strs), 1);
	}
	else
		return (ft_error("Parameter missing before the map"), 1);
	free_strs(strs);
	return (0);
}

int	check_texture(t_data *data, int fd)
{
	char	*line;

	while (!check_empty(data->textures, 4)
		|| data->floor.r == -1
		|| data->ceiling.r == -1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (check_logic(data, line))
			return (free(line), free_textures(data->textures), 1);
		free(line);
	}
	if (!check_empty(data->textures, 4)
		|| data->floor.r == -1
		|| data->ceiling.r == -1)
		return (ft_error("Missing info"), free_textures(data->textures), 1);
	return (0);
}
