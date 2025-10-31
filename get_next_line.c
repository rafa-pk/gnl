/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:56:43 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/10/31 14:59:26 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buff[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(1);
	if (!line)
		return (NULL);
	while (buff[0] || (read(fd, buff, BUFFER_SIZE) > 0))
	{
		line = gnl_strjoin(buff, line);
		if (!line)
			return (NULL);
		clean_buff(buff);
		if (line[gnl_strlen(line) - 1] == '\n')
			return (line);
	}
	return (line);
}

#include <stdio.h>
int	main(void)
{
	int		fd;
//	int		i;
	char	*line;

//	i = 0;
	fd = open("a.out", O_RDONLY);
	line = NULL;
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	printf("%s\n", line);
	/*	
	while (i < 147)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i++;
	}*/
	return (0);
}
