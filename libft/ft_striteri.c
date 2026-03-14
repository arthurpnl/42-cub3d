/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 06:33:05 by skoudad           #+#    #+#             */
/*   Updated: 2024/11/17 06:41:44 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}	
}
/*
#include <stdio.h>

// Prototype de ft_striteri
void ft_striteri(char *s, void (*f)(unsigned int, char*));

// Fonction à appliquer
void to_uppercase_on_even_index(unsigned int i, char *c) {
    if (i % 2 == 0 && *c >= 'a' && *c <= 'z') {
        *c = *c - 32;  // Convertir en majuscule
    }
}

int main() {
    char str[] = "hello, world!";

    printf("Avant : %s\n", str);
    ft_striteri(str, to_uppercase_on_even_index);
    printf("Après : %s\n", str);

    return 0;
}*/
