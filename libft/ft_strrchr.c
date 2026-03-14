/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:23:45 by skoudad           #+#    #+#             */
/*   Updated: 2024/11/25 21:03:48 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char) c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main() {
    const char str[] = "Hello, World!";
    char ch = 'o';

    char *result = ft_strrchr(str, ch);

    if (result != NULL) {
        printf("Dernière occurrence de '%c' trouvée à la position : 
	%ld\n", ch, result - str);
    } else {
        printf("Le caractère '%c' n'a pas été trouvé.\n", ch);
    }

    return 0;
}
*/
