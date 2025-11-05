/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:57:29 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/11/05 18:18:21 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static ssize_t	read_line(int fd, char *buff)
{
	ssize_t	by;

	by = read(fd, buff, BUFFER_SIZE);
	if (by < 0)
		return (buff[0] = '\0', -1);
	return (by);
}

char	*get_next_line(int fd)
{
	ssize_t		by;
	char		*line;
	static char	buff[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	by = 1;
	while (!ft_strchr(line, '\n') && by > 0)
	{
		if (buff[0] == '\0')
			by = read_line(fd, buff);
		if (by == -1 || (by == 0 && line[0] == '\0'))
			return (free(line), NULL);
		line = gnl_strjoin(line, buff);
		if (!line)
			return (NULL);
		clean_buff(buff);
		if (line[0] == '\0')
			return (free(line), NULL);
	}
	return (line);
}
/*
#include <stdio.h>

int	main(void)
{
	int	fd;
	char	*line;

	fd = open("test2.txt", O_RDONLY);
	line = get_next_line(fd);
	//printf("%s", line);
	//free(line);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}*/
