/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:03:55 by skoudad           #+#    #+#             */
/*   Updated: 2024/11/16 16:07:23 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	const unsigned char	*p;

	p = ptr;
	while (num--)
	{
		if (*p == (unsigned char)value)
			return ((void *)p);
		p++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main() {
    char buffer[] = "Hello, World!";
    char target = 'o';

    char *result = ft_memchr(buffer, target, sizeof(buffer));

    if (result != NULL) {
        printf("Caractère '%c' trouvé à la position : %ld\n",
       	target, result - buffer);
    } else {
        printf("Caractère '%c' non trouvé dans la zone mémoire.\n", target);
    }

    return 0;
}
*/
