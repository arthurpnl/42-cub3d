/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:04:39 by skoudad           #+#    #+#             */
/*   Updated: 2024/11/23 20:26:30 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *s, size_t dstsize)
{
	size_t		dst_len;
	size_t		index;
	size_t		i;

	dst_len = ft_strlen(dst);
	index = 0;
	while (dst[index])
		index++;
	i = 0;
	while (s[i] && (i + index + 1) < dstsize)
	{
		dst[index + i] = s[i];
		i++;
	}
	if (i < dstsize)
		dst[index + i] = '\0';
	if (dstsize <= dst_len)
		return (ft_strlen(s) + dstsize);
	else
		return (ft_strlen(s) + dst_len);
}
/*
#include <stdio.h>
#include <string.h>

int main() {
    char dest[10] = "Hello, ";
    const char *src = "world!";

    size_t len = ft_strlcat(dest, src, sizeof(dest));

    // La chaîne résultante est tronquée et le caractère nul est ajouté
    printf("Chaîne résultante : '%s'\n", dest);  // Résultat : "Hello, wo"
    printf("Longueur totale : %zu\n", len); 

    return 0;
}*/
