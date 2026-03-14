/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:49:43 by skoudad           #+#    #+#             */
/*   Updated: 2024/11/20 18:23:06 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
#include <unistd.h>
#include <fcntl.h>  // Pour open

void ft_putchar_fd(char c, int fd);

int main() {
    // Écrire sur stdout (écran)
    ft_putchar_fd('A', 1);
    ft_putchar_fd('\n', 1);

    // Écrire sur stderr (erreurs)
    ft_putchar_fd('B', 2);
    ft_putchar_fd('\n', 2);

    // Écrire dans un fichier
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd >= 0) {
        ft_putchar_fd('C', fd);
        ft_putchar_fd('\n', fd);
        close(fd); // Toujours fermer les fichiers ouverts
    }

    return 0;
}
*/
