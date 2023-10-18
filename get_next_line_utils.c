/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: <wtangcha> <wtangcha@student.42bangkok.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:38:35 by <wtangcha>        #+#    #+#             */
/*   Updated: 2023/10/18 10:15:23 by <wtangcha>       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// [sting lenght] find the first \n in the string and return the index of it
int	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

/* [string (find) character] uses a pointer to str
to iterate through the string, and returns a pointer
to the first occurrence of c in the string
if c == '\0', return poointer to null terminator character
 */
char	*ft_strchr(char *str, int c)
{
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

/* [string join (concatenate )] Takes two strings as input
and concatenates them together into a new string.
 given s1 = *str, s2 = buffer */
char	*ft_strjoin(char *str, char *buffer)
{
	size_t		i;
	size_t		j;
	char		*catstr;

	i = -1;
	j = 0;
	if (!str)
	{
		str = (char *)malloc(1 * sizeof(char));
		str[0] = '\0';
	}
	if (!str || !buffer)
		return (NULL);
	catstr = (char *)malloc(
			sizeof(char) * (ft_strlen(str) + ft_strlen(buffer) + 1));
	if (!catstr)
		return (NULL);
	if (str)
		while (str[++i] != '\0')
			catstr[i] = str[i];
	while (buffer[j] != '\0')
		catstr[i++] = buffer[j++];
	catstr[ft_strlen(str) + ft_strlen(buffer)] = '\0';
	free(str);
	return (catstr);
}
