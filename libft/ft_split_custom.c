/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 02:10:35 by skoudad           #+#    #+#             */
/*   Updated: 2026/01/22 02:10:35 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_separator(char c, char const *seps)
{
	int	i;

	i = 0;
	while (seps[i])
	{
		if (c == seps[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	count_words(char const *s, char const *seps)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (!is_separator(s[i], seps)
			&& (is_separator(s[i + 1], seps) || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static void	fill_tab(char *new, char const *s, char const *seps)
{
	size_t	i;

	i = 0;
	while (s[i] && !is_separator(s[i], seps))
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
}

static void	set_mem(char **tab, char const *s, char const *seps)
{
	size_t	count;
	size_t	index;
	size_t	i;

	index = 0;
	i = 0;
	while (s[index])
	{
		count = 0;
		while (s[index + count] && !is_separator(s[index + count], seps))
			count++;
		if (count > 0)
		{
			tab[i] = malloc(sizeof(char) * (count + 1));
			if (!tab[i])
				return ;
			fill_tab(tab[i], (s + index), seps);
			i++;
			index = index + count;
		}
		else
			index++;
	}
	tab[i] = 0;
}

char	**ft_split_custom(char const *s, char const *seps)
{
	size_t	words;
	char	**tab;

	words = count_words(s, seps);
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	set_mem(tab, s, seps);
	return (tab);
}
