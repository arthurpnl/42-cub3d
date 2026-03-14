/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:06:55 by skoudad           #+#    #+#             */
/*   Updated: 2024/11/20 20:46:57 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
/*
#include <unistd.h> // Pour write
#include <fcntl.h>  // Pour open

void ft_putendl_fd(char *s, int fd);

int main(void)
{
    int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644); 
// Ouvre un fichier pour écrire
    if (fd < 0)
        return 1;

    ft_putendl_fd("Bonjour, monde !", fd); // Écrit dans le fichier
    ft_putendl_fd("Ceci est un test.", fd);

    close(fd); // Ferme le fichier
    return 0;
}
*/
