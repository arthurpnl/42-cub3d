/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 21:06:21 by skoudad           #+#    #+#             */
/*   Updated: 2026/02/14 18:26:14 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_parsing(t_data *data)
{
	free_textures(data->textures);
	free_strs(data->map);
}

int	main(int ac, char **av)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	if (ac != 2)
		return (ft_error("Wrong number of arguments"), 1);
	if (parsing(&data, av[1]))
		return (1);
	if (rendering(&data))
		return (free_parsing(&data), 1);
	free_parsing(&data);
	return (0);
}
