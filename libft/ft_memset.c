/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:48:36 by skoudad           #+#    #+#             */
/*   Updated: 2024/11/16 20:45:06 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*p;

	p = (unsigned char *)ptr;
	while (num--)
		*p++ = (unsigned char)value;
	return (ptr);
}
/*
#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];

    // Remplit les 10 octets de `buffer` avec le caractère 'A' (ASCII 65)
    memset(buffer, 'A', sizeof(buffer));

    // Ajoute un caractère nul à  caractères valide
    buffer[9] = '\0';

    printf("Contenu du buffer : %s\n", buffer);

    return 0;
}*/
