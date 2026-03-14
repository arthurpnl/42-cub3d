/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:52:47 by skoudad           #+#    #+#             */
/*   Updated: 2024/11/25 20:51:05 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		i;

	i = 0;
	while (src[i] && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
	{
		dst[i] = '\0';
		i++;
	}
	return (ft_strlen(src));
}
/*
#include <stdio.h>

int main()
{
    char dst[10];
    const char *src = "Hello, world!";
    
    size_t len = ft_strlcpy(dst, src, sizeof(dst));
    
    printf("Destination: '%s'\n", dst);  // Output: "Hello, wo"
    printf("Source length: %zu\n", len); // Output: 13
    
    return 0;
}*/
