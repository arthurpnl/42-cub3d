/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:56:22 by skoudad           #+#    #+#             */
/*   Updated: 2024/11/16 20:46:54 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*ptr;

	total_size = nmemb * size;
	if (nmemb != 0 && total_size / nmemb != size)
		return (NULL);
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total_size);
	return (ptr);
}
/*
#include <stdio.h>  // Pour printf

int main() {
    // Allocation d'un tableau de 10 entiers
    int *array = (int *)ft_calloc(10, sizeof(int));

    if (array == NULL) {
        printf("Erreur : impossible d'allouer la mémoire.\n");
        return 1;
    }

    // Affichage des valeurs (toutes initialisées à 0)
    for (int i = 0; i < 10; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }

    // Libération de la mémoire
    free(array);

    return 0;
}
*/
