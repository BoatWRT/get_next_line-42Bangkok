/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: <wtangcha> <wtangcha@student.42bangkok.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:37:50 by <wtangcha>        #+#    #+#             */
/*   Updated: 2023/10/03 11:42:34 by <wtangcha>       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This is a function that returns a line read from a file descriptor.

#include "get_next_line.h"

char	*get_next_line(int fd)
{
		static char	*full_str;
		char		*line;

		if (fd < 0 || BUFFER_SIZE <= 0)
			return (NULL);
		// read first line of fd
		full_str = read_first_line(fd, full_str);
		if (!full_str)
			return (NULL);
		// from the read string ,take the first line and return it
		line = get_first_line(full_str);
		// from the read string ,take the first line and remove it. returns the rest
		full_str = remove_first_line(full_str);
	return (line);
}

// read first line of fd
char read_first_line(int fd, char *str)
{
	char *buffer;
	int nbytes_read;

	nbytes_read = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	// read until the end of the line
	while(!ft_strchr(str, '\n') && nbytes_read != 0)
	{
		nbytes_read = read(fd, buffer, BUFFER_SIZE);
		// if read error
		if (nbytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[nbytes_read] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

// from the read string ,take the first line and return it
char *get_first_line(char *str)
{
	int	i;
	int	line_len;
	char	*line;

	i = 0;
	line_len = 0;
	if (!str)
		return (NULL);
	// count the length of the first line
	while (str[line_len] != '\n' && str[line_len] != '\0')
		line_len++;
	line = (char *)malloc(sizeof(char) * (line_len + 1));
	if (!line)
		return (NULL);
	while (i < line_len)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

// from the read string ,take the first line and remove it. returns the rest
// i = first line length, j = rest of string length
char *remove_first_line(char *str)
{
	char *rest_str;
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	// count the length of the first line
	while (str[i] && str[i] != '\n')
		i++;
	rest_str = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!rest_str)
		return (NULL);
	// copy the rest of the string [i + 1 to skip '\n' of the new line]
	while (str[i + 1])
	{
		rest_str[j] = str[i + 1];
		i++;
		j++;
	}
	rest_str[j] = '\0';
	free(str);
	return (rest_str);
}


int	main(void)
{
	int	fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	line = get_next_line(fd);
	printf("%s\n", line);
	line = get_next_line(fd);
	printf("%s\n", line);
	return (0);
}

