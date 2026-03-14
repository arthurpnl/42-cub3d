/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:41:58 by skoudad           #+#    #+#             */
/*   Updated: 2026/02/14 17:14:57 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_line	*fill_line(char *line)
{
	t_line	*current;

	current = malloc(sizeof(t_line));
	if (!current)
		return (NULL);
	current->next = NULL;
	current->str = line;
	return (current);
}

void	free_line(t_line *curr, bool free_str)
{
	t_line	*next;

	while (curr)
	{
		next = curr->next;
		if (free_str)
			free(curr->str);
		free(curr);
		curr = next;
	}
}
