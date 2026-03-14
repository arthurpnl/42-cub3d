/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 05:54:48 by skoudad           #+#    #+#             */
/*   Updated: 2024/11/17 06:31:24 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	char			*new;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	new = (char *)malloc(sizeof(char) * (len +1));
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = f(i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
/*
#include <stdio.h>

// Exemple de fonction qui transforme le caractère selon son index
char to_uppercase(unsigned int i, char c) {
    if (i % 2 == 0) {
        return c - 32;  // Convertir en majuscule si l'index est pair
    }
    return c;  // Laisser le caractère inchangé si l'index est impair
}

int main() {
    char *s = "hello, world!";
    char *result = ft_strmapi(s, to_uppercase);

    if (result) {
        printf("Résultat de ft_strmapi : %s\n", result);
        free(result);  // Libérer la mémoire allouée
    } else {
        printf("Erreur d'allocation mémoire\n");
    }

    return 0;
}*/
