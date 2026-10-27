/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpagkalo <kpagkalo@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 12:27:53 by kpagkalo          #+#    #+#             */
/*   Updated: 2026/10/19 12:27:56 by kpagkalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	find_newline(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		k;

	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (s1 && s1[i])
		new[k++] = s1[i++];
	i = 0;
	while (s2[i])
		new[k++] = s2[i++];
	new[k] = '\0';
	return (new);
}

char	*extract_line(char *stash)
{
	char	*line;
	int		i;
	int		k;

	k = 0;
	if (stash == NULL)
		return (NULL);
	i = find_newline(stash);
	if (i == -1)
		i = ft_strlen(stash);
	line = malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	while (k <= i)
	{
		line[k] = stash[k];
		k++;
	}
	line[k] = '\0';
	return (line);
}

char	*trim_stash(char *stash)
{
	char	*new;
	int		i;
	int		k;

	i = find_newline(stash) + 1;
	if (stash == NULL || stash[0] == '\0')
	{
		free(stash);
		return (NULL);
	}
	if (i == 0)
		i = ft_strlen(stash);
	new = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (new == NULL)
	{
		free(stash);
		return (NULL);
	}
	k = 0;
	while (stash[i])
		new[k++] = stash[i++];
	new[k] = '\0';
	free(stash);
	return (new);
}
