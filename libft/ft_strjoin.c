/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 22:51:05 by skoudad           #+#    #+#             */
/*   Updated: 2024/11/17 00:01:12 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len1;
	size_t	len;
	size_t	i;

	len1 = ft_strlen(s1);
	len = len1 + ft_strlen(s2);
	new = (char *)malloc(len +1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		new[i] = s1[i];
		i++;
	}
	while (i < len)
	{
		new[i] = s2[i - len1];
		i++;
	}	
	new[i] = '\0';
	return (new);
}
/*
#include <stdio.h>
#include <stdlib.h>

char *ft_strjoin(char const *s1, char const *s2);

int main(void)
{
    char *s1 = "Hello, ";
    char *s2 = NULL;

    char *result = ft_strjoin(s1, s2);
    if (result)
    {
        printf("Résultat : %s\n", result);  // Doit afficher "Hello, "
        free(result);  // N'oublie pas de libérer la mémoire allouée.
    }
    else
    {
        printf("Erreur d'allocation de mémoire\n");
    }

    return 0;
}
*/
