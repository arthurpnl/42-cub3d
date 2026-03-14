/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:17:00 by skoudad           #+#    #+#             */
/*   Updated: 2024/11/20 20:13:31 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}
/*
#include <unistd.h> // Pour write
#include <fcntl.h>  // Pour open

void ft_putnbr_fd(int n, int fd);

int main(void)
{
    int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644); 
// Ouvre un fichier
    if (fd < 0)
        return 1;

    ft_putnbr_fd(42, fd);       // Écrit "42" dans le fichier
    ft_putnbr_fd(-1234, fd);    // Écrit "-1234" dans le fichier
    ft_putnbr_fd(0, fd);        // Écrit "0" dans le fichier
    ft_putnbr_fd(-2147483648, fd); // Écrit "-2147483648" dans le fichier

    close(fd); // Ferme le fichier
    return 0;
}*/
