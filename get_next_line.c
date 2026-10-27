/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpagkalo <kpagkalo@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 12:27:09 by kpagkalo          #+#    #+#             */
/*   Updated: 2026/10/19 12:27:17 by kpagkalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_stash(int fd, char *stash, char *buffer)
{
	int		bytes;
	char	*tmp;

	bytes = 1;
	while (bytes > 0 && find_newline(stash) == -1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(stash);
			return (NULL);
		}
		buffer[bytes] = '\0';
		tmp = stash;
		stash = ft_strjoin(stash, buffer);
		free(tmp);
		if (stash == NULL)
			return (NULL);
	}
	return (stash);
}

char	*read_to_stash(int fd, char *stash)
{
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
	{
		free(stash);
		return (NULL);
	}
	stash = fill_stash(fd, stash, buffer);
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(fd, stash);
	if (stash == NULL)
		return (NULL);
	line = extract_line(stash);
	if (line == NULL)
		return (NULL);
	stash = trim_stash(stash);
	if (stash == NULL)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

#include <stdio.h>
#include <fcntl.h>

int main(int argc , char **argv)
{
	int fd;
	int max;
	int n;
	char *line;

	if (argc < 2)
		return (1);
	fd = open(argv[1],O_RDONLY);
	max = -1;
	if (argc == 3)
		max = atoi(argv[2]);
	n = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s",line);
		free(line);
		n++;
		if (n == max)
			break;
		line = get_next_line(fd);
	}
	close(fd)

}