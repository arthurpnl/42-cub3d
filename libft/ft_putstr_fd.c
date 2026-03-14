/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:36:41 by skoudad           #+#    #+#             */
/*   Updated: 2024/11/20 18:49:30 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}
/*
#include <unistd.h> // Pour write
#include <fcntl.h>  // Pour open

void ft_putstr_fd(char *s, int fd);

int main() {
    // Tester sur stdout (écran)
    ft_putstr_fd("Hello, world!\n", 1);

    // Tester sur stderr (erreurs)
    ft_putstr_fd("This is an error message.\n", 2);

    // Tester sur un fichier
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd >= 0) {
        ft_putstr_fd("Writing to a file.\n", fd);
        close(fd); // Toujours fermer le fichier
    }

    // Tester avec une chaîne NULL
    ft_putstr_fd(NULL, 1); // Cela ne doit rien afficher

    return 0;
}
*/
