/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:58:55 by skoudad           #+#    #+#             */
/*   Updated: 2024/11/26 20:02:45 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_n;
	size_t	i;
	size_t	j;

	if (ft_strlen(needle) == 0)
		return ((char *) haystack);
	len_n = ft_strlen(needle);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] && haystack[i + j] == needle[j] && i + j < len)
			j++;
		if (j == len_n)
			return ((char *) haystack + i);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main() {
    const char *haystack = "Hello, this is a test string!";
    const char *needle = "this";
    size_t len = 20; // Limiter la recherche aux 20 premiers caractères

    char *result = ft_strnstr(haystack, needle, len);

    if (result) {
        printf("Trouvé : %s\n", result);
    } else {
        printf("Non trouvé\n");
    }

    return 0;
}
*/
