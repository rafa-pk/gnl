/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:56:43 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/10/31 15:35:52 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t		by;
	char		*line;
	static char	buff[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(1);
	if (!line)
		return (free(line), NULL);
	by = 1;
	while (buff[0] || (by > 0))
	{
		by = read(fd, buff, BUFFER_SIZE);
		if (by < 0)
			return (free(line), NULL);
		line = gnl_strjoin(buff, line);
		if (!line)
			return (NULL);
		clean_buff(buff);
		if (line[gnl_strlen(line) - 1] == '\n')
			return (line);
	}
	return (line);
}
/*
#include <stdio.h>
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test2.txt", O_RDONLY);
	line = NULL;
	if (fd == -1)
		return (1);
//	line = get_next_line(fd);
//	printf("%s\n", line);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	return (0);
}*/
