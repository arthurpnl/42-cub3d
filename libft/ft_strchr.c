/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:49:56 by skoudad           #+#    #+#             */
/*   Updated: 2024/11/24 19:56:07 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			break ;
		i++;
	}
	if (s[i] == (char) c)
		return ((char *) s + i);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main() {
    const char str[] = "Hello, World!";
    char ch = 'o';

    char *result = ft_strchr(str, ch);

    if (result != NULL) {
        printf("Le caractère '%c' trouvé à la position : 
	%ld\n", ch, result - str);
    } else {
        printf("Le caractère '%c' n'a pas été trouvé.\n", ch);
    }

    return 0;
}*/
