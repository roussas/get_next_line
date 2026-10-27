/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpagkalo <kpagkalo@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 12:27:32 by kpagkalo          #+#    #+#             */
/*   Updated: 2026/10/19 12:27:36 by kpagkalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*read_to_stash(int fd, char *stash);
char	*get_next_line(int fd);
char	*fill_stash(int fd, char *stash, char *buffer);
int		ft_strlen(char *s);
int		find_newline(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*extract_line(char *stash);
char	*trim_stash(char *stash);

#endif
