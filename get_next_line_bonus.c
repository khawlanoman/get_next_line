/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khnoman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:49:22 by khnoman           #+#    #+#             */
/*   Updated: 2025/11/17 18:31:04 by khnoman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

static char	*read_file(int fd, char *stash)
{
	ssize_t	read_byte;
	char	*buffer;

	read_byte = 1;
	buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buffer)
		return (NULL);
	if (fd == -1)
		return (NULL);
	while ((!stash || !ft_strchr(stash, '\n')) && read_byte > 0)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte < 0)
		{
			free(stash);
			free(buffer);
			return (NULL);
		}
		buffer[read_byte] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (NULL);
	}
	free(buffer);
	return (stash);
}

static char	*set_line(char *line)
{
	ssize_t	i;
	ssize_t	j;
	char	*line_c;

	j = 0;
	i = 0;
	if (line[0] == '\0')
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		line_c = malloc((i + 2) * sizeof(char));
	else
		line_c = malloc((i + 1) * sizeof(char));
	if (!line_c)
		return (NULL);
	while (j <= i && line[j])
	{
		line_c[j] = line[j];
		j++;
	}
	line_c[j] = '\0';
	return (line_c);
}

static char	*extract_line(char *line)
{
	ssize_t	i;
	char	*left;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	if (line[i] == '\n')
		i++;
	left = ft_substr(line, i, ft_strlen(line) - i);
	free(line);
	return (left);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	if (!stash[fd])
		stash[fd] = ft_strdup("");
	stash[fd] = read_file(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = set_line(stash[fd]);
	if (!line)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	stash[fd] = extract_line(stash[fd]);
	if (!stash[fd] || stash[fd][0] == '\0')
	{
		free(stash[fd]);
		stash[fd] = NULL;
	}
	return (line);
}
