/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:59:09 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/11/05 17:15:41 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, int c)
{
	size_t			i;
	unsigned char	ch;

	i = 0;
	ch = (unsigned char) c;
	while (str[i])
	{
		if (str[i] == ch)
			return ((char *) &str[i]);
		i++;
	}
	if (ch == '\0')
		return ((char *) &str[i]);
	return (NULL);
}

size_t	gnl_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*gnl_strjoin(char *line, char *buff)
{
	size_t	i;
	size_t	j;
	char	*join;

	i = 0;
	j = 0;
	join = malloc(sizeof(char) * (gnl_strlen(line) + gnl_strlen(buff) + 1));
	if (!join)
		return (free(line), NULL);
	while (line[i])
	{
		join[i] = line[i];
		i++;
	}
	while (buff[j] && buff[j] != '\n')
	{
		join[i + j] = buff[j];
		j++;
	}
	if (buff[j] == '\n')
		join[i + j++] = '\n';
	join[i + j] = '\0';
	return (free(line), join);
}

char	*clean_buff(char *buff)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (buff[i] != '\n' && buff[i])
		i++;
	if (buff[i] == '\n')
		i++;
	while (buff[i])
		buff[j++] = buff[i++];
	while (j < BUFFER_SIZE)
		buff[j++] = '\0';
	return (buff);
}
