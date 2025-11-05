/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:57:29 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/11/05 19:22:14 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	buff[FOPEN_MAX][BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	by = 1;
	while (!ft_strchr(line, '\n') && by > 0)
	{
		if (buff[fd][0] == '\0')
			by = read_line(fd, buff[fd]);
		if (by == -1 || (by == 0 && line[0] == '\0'))
			return (free(line), NULL);
		line = gnl_strjoin(line, buff[fd]);
		if (!line)
			return (NULL);
		clean_buff(buff[fd]);
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
	int fd2;
	int	fd3;
	char	*line;

	fd = open("test2.txt", O_RDONLY);
	fd2 = open("bible.txt", O_RDONLY);
	fd3 = open("get_next_line.c", O_RDONLY);
	line = get_next_line(fd);
	//printf("%s", line);
	//free(line);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	printf("\n\na few lines from the bible to inspire:\n");
	line = get_next_line(fd2);
	int i = 0;
	while (i < 5)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd2);
		i++;
	}
	if (line)
		free(line);
	printf("\n\nmy gnl function:\n");
	i = 0;
	line = get_next_line(fd3);
	while (i < 15)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd3);
		i++;
	}
	if (line)
		free(line);
	printf("\n\nand now some more bible:\n");
	i = 0;
	line = get_next_line(fd2);
	while (i < 10)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd2);
		i++;
	}
	if (line)
		free(line);
	i = 0;
	line = get_next_line(fd3);
	printf("\n\nand the rest of gnl:\n");
	while (i < 37)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd3);
		i++;
	}
	free(line);
	return (0);
}*/
