/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 21:06:21 by skoudad           #+#    #+#             */
/*   Updated: 2026/02/14 18:26:14 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_empty(char **strs, int expected_len)
{
	int	i;
	int	nb_not_null;

	i = 0;
	nb_not_null = 0;
	while (i < expected_len)
	{
		if (strs[i++])
			nb_not_null++;
	}
	return (nb_not_null == expected_len);
}
