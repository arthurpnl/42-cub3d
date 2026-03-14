/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:13:59 by skoudad           #+#    #+#             */
/*   Updated: 2024/11/24 18:46:39 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\t')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
	{	
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + (str[i++] - '0');
	return (res * sign);
}
/*
#include <stdio.h>
int main() {
    const char *str1 = "   -12345";
    const char *str2 = "42";
    const char *str3 = "   +789abc";  
// Chaîne invalide (les caractères après les chiffres seront ignorés)
    const char *str4 = "not_a_number";  // Chaîne invalide, retourne 0

    printf("my_atoi(str1) = %d\n", ft_atoi(str1));  // Devrait afficher -12345
    printf("my_atoi(str2) = %d\n", ft_atoi(str2));  // Devrait afficher 42
    printf("my_atoi(str3) = %d\n", ft_atoi(str3));  // Devrait afficher 789
    printf("my_atoi(str4) = %d\n", ft_atoi(str4));  // Devrait afficher 0

    return 0;
}*/
