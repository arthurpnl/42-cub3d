/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 05:05:59 by skoudad           #+#    #+#             */
/*   Updated: 2025/02/21 12:11:42 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*function_name(int fd, char *buf, char *backup)
{
	int		read_line;
	char	*char_temp;

	read_line = 1;
	while (read_line != '\0')
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line == -1)
			return (0);
		else if (read_line == 0)
			break ;
		buf[read_line] = '\0';
		if (!backup)
			backup = ft_strdup("");
		char_temp = backup;
		backup = ft_strjoin(char_temp, buf);
		free(char_temp);
		char_temp = NULL;
		if (ft_strchr (buf, '\n'))
			break ;
	}
	return (backup);
}

static char	*extract(char *line)
{
	size_t	count;
	char	*backup;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (0);
	backup = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	line[count + 1] = '\0';
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*backup[FD_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FD_MAX - 1)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	line = function_name(fd, buf, backup[fd]);
	free(buf);
	buf = NULL;
	if (!line)
	{
		free(backup[fd]);
		backup[fd] = NULL;
		return (NULL);
	}
	backup[fd] = extract(line);
	return (line);
}
/*
#include <stdio.h>
int main()
{
    int fd1 = open("./1char.txt", O_RDONLY); // Ouvrir le premier fichier
    int fd2 = open("./file2.txt", O_RDONLY); // Ouvrir le deuxième fichier

    if (fd1 < 0 || fd2 < 0)
    {
        perror("Erreur lors de l'ouverture des fichiers");
        return 1;
    }

    char *line1, *line2;

    // Lire les fichiers en parallèle
    while ((line1 = get_next_line(fd1)) || (line2 = get_next_line(fd2)))
    {
        if (line1) 
        {
            printf("Fichier 1 : %s", line1);
            free(line1);
        }
        if (line2) 
        {
            printf("Fichier 2 : %s", line2);
            free(line2);
        }
    }

    close(fd1);
    close(fd2);
    return 0;
}
*/
