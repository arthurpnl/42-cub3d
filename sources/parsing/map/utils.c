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

// linked list len
static int	count_line(t_line *curr)
{
	int	len;

	len = 0;
	while (curr)
	{
		curr = curr->next;
		len++;
	}
	return (len);
}

//linked list to char **
char	**map_table(t_line *curr)
{
	char	**table;
	int		size;
	int		i;
	int		size_line;

	size = count_line(curr);
	table = (char **)malloc(sizeof(char *) * (size + 1));
	if (!table)
		return (NULL);
	i = 0;
	while (i < size)
	{
		size_line = ft_strlen(curr->str);
		if (size_line > 0 && curr->str[size_line - 1] == '\n')
			curr->str[size_line - 1] = '\0';
		table[i] = curr->str;
		curr = curr->next;
		i++;
	}
	table[i] = NULL;
	return (table);
}

// is c in str
int	is_in(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	**ft_strsdup(char **srcs)
{
	char	**dests;
	int		i;

	dests = (char **)malloc(sizeof(char *) * (ft_strslen(srcs) + 1));
	if (!dests)
		return (NULL);
	i = 0;
	while (srcs[i])
	{
		dests[i] = ft_strdup(srcs[i]);
		if (!dests[i])
		{
			i--;
			while (i >= 0)
				free(dests[i--]);
			return (free(dests), NULL);
		}
		i++;
	}
	dests[i] = NULL;
	return (dests);
}
