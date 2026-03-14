/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:42:06 by skoudad           #+#    #+#             */
/*   Updated: 2026/01/22 21:19:06 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1 && s2 && s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

/*
#include <stdio.h>
#include <string.h>

int main() {
    const char *str1 = "applepie";
    const char *str2 = "applesauce";

    if (ft_strncmp(str1, str2, 5) == 0) {
        printf("Les 5 premiers caractères sont identiques.\n");
    } else {
        printf("Les 5 premiers caractères diffèrent.\n");
    }

    return 0;
}
*/
