/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:09:00 by skoudad           #+#    #+#             */
/*   Updated: 2024/11/23 20:34:12 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && *(unsigned char *)(s1 + i) == *(unsigned char *)(s2 + i))
		i++;
	if (i < n)
		return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main() {
    unsigned char arr1[] = {0x11, 0x02, 0x03};
    unsigned char arr2[] = {0x01, 0x02, 0x04};

    int result = ft_memcmp(arr1, arr2, 3);

    if (result < 0) {
        printf("arr1 est inférieur à arr2.\n");
    } else if (result == 0) {
        printf("arr1 est égal à arr2.\n");
    } else {
        printf("arr1 est supérieur à arr2.\n");
    }

    return 0;
}
*/
