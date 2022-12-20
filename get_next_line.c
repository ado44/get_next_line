/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <amarna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:43:33 by amarna            #+#    #+#             */
/*   Updated: 2022/10/20 18:57:03 by amarna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
/*We will read from the fd in a loop
until we detect a \n or the end of the file
We create a reading loop that stops when the read function returns 0 
(which means we are at the end of the file and there is nothing left to read)
or a n
We save the read characters in a static variable*/

char	*read_from_fd(int fd, char *static_line)
{
	int		reader;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	reader = 1;
	while (reader)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[reader] = '\0';
		static_line = ft_strjoin(static_line, buffer);
		if (is_newline(static_line))
			break ;
	}
	free(buffer);
	return (static_line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_from_fd(fd, line);
	if (!line)
		return (NULL);
	str = get_returned_line(line);
	line = free_str_from_stat(line);
	return (str);
}
