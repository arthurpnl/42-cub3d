/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:30:51 by skoudad           #+#    #+#             */
/*   Updated: 2024/11/16 22:49:45 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		new = (char *)malloc(1);
		if (new)
			*new = '\0';
		return (new);
	}	
	if (start + len > s_len)
		len = s_len - start;
	new = (char *)malloc(len + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
/*
#include <stdio.h>
#include <stdlib.h>

char    *ft_substr(char const *s, unsigned int start, size_t len);

int main(void)
{
    char *s = "Hello, world!";
    char *sub;

    sub = ft_substr(s, 7, 5); // Extract "world"
    if (sub)
    {
        printf("Substring: '%s'\n", sub);
        free(sub);
    }

    sub = ft_substr(s, 13, 5); // Out of bounds: ""
    if (sub)
    {
        printf("Substring: '%s'\n", sub);
        free(sub);
    }

    sub = ft_substr(s, 0, 20); // Entire string: "Hello, world!"
    if (sub)
    {
        printf("Substring: '%s'\n", sub);
        free(sub);
    }

    return 0;
}*/
