/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:49:51 by skoudad           #+#    #+#             */
/*   Updated: 2024/11/15 15:26:06 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
		*p++ = 0;
}
/*
#include <stdio.h>

int main() {
    char buffer[10];

    // Remplit le buffer avec 'A'
    for (int i = 0; i < 10; i++) {
        buffer[i] = 'A';
    }

    // Affiche le contenu avant bzero
    printf("Avant bzero : ");
    for (int i = 0; i < 10; i++) {
        printf("%c ", buffer[i]);
    }
    printf("\n");

    // Met à zéro les 5 premiers octets
    bzero(buffer, 5);

    // Affiche le contenu après bzero
    printf("Après bzero : ");
    for (int i = 0; i < 10; i++) {
        printf("%c ", buffer[i] ? buffer[i] : '0');
    }
    printf("\n");

    return 0;
}*/
