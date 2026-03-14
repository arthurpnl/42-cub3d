/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 00:00:00 by skoudad           #+#    #+#             */
/*   Updated: 2026/02/07 16:50:27 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_suffix(char *path, char *suffix)
{
	int	len;
	int	len_suffix;

	len_suffix = ft_strlen(suffix);
	len = ft_strlen(path);
	if (len < len_suffix
		|| ft_strncmp(path + len - len_suffix, suffix, len_suffix) != 0)
		return (1);
	return (0);
}

void	free_textures(char **textures)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (textures[i])
		{
			free(textures[i]);
			textures[i] = NULL;
		}
		i++;
	}
}
