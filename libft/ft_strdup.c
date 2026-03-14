/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:47:28 by skoudad           #+#    #+#             */
/*   Updated: 2024/11/26 19:57:49 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	i;

	i = 0;
	copy = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (copy == NULL)
		return (NULL);
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
/*
#include <stdio.h>

int main() {
    const char *original = "Hello, strdup!";
    char *copy = ft_strdup(original);

    if (copy == NULL) {
        printf("Erreur : impossible d'allouer de la mémoire.\n");
        return 1;
    }

    printf("Original : %s\n", original);
    printf("Copie    : %s\n", copy);

    free(copy); // Libérer la mémoire allouée
    return 0;
}
*/
