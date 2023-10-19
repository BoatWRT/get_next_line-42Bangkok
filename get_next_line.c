/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: <wtangcha> <wtangcha@student.42bangkok.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:37:50 by <wtangcha>        #+#    #+#             */
/*   Updated: 2023/10/19 17:13:56 by <wtangcha>       ###   ########.fr       */
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
	full_str = ft_read_first_line(fd, full_str);
	if (!full_str)
		return (NULL);
	line = ft_get_first_line(full_str);
	full_str = ft_remove_first_line(full_str);
	return (line);
}

// read first line of fd
// read 'til the end of the line if that str != '\n' & not EOF
// if nbytes_read == -1 ,read error
char	*ft_read_first_line(int fd, char *str)
{
	char	*buffer;
	int		nbytes_read;

	nbytes_read = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(str, '\n') && nbytes_read != 0)
	{
		nbytes_read = read(fd, buffer, BUFFER_SIZE);
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
// count the length of the first line [line_len]
// [line_len + 2] allocate for '\n' and '\0'
char	*ft_get_first_line(char *str)
{
	int		i;
	int		line_len;
	char	*line;

	i = 0;
	line_len = 0;
	if (!str[line_len] || !str)
		return (NULL);
	while (str[line_len] && str[line_len] != '\n')
		line_len++;
	line = (char *)malloc(sizeof(char) * (line_len + 2));
	if (!line)
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

// from the read string ,take the first line and remove it. returns the rest
// i = first line length, j = rest of string length
// while (str[i + 1]), copy the rest of the string
// [i + 1 to skip '\n' of the new line]
char	*ft_remove_first_line(char *str)
{
	char	*rest_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	rest_str = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!rest_str)
		return (NULL);
	while (str[i + 1])
		rest_str[j++] = str[i++ + 1];
	rest_str[j] = '\0';
	free(str);
	return (rest_str);
}

/*
if wanna test
#include <fcntl.h>
#include <stdio.h>
 gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42
 get_next_line.c get_next_line_utils.c
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
*/
