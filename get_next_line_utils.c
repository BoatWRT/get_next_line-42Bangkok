/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: <wtangcha> <wtangcha@student.42bangkok.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:38:35 by <wtangcha>        #+#    #+#             */
/*   Updated: 2023/10/03 10:38:36 by <wtangcha>       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// [sting lenght] find the first \n in the string and return the index of it
int ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

// [string (find) character] uses a pointer to str to iterate through the string,
// and returns a pointer to the first occurrence of c in the string
char	*ft_strchr(char *str, int c)
{
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	// return poointer to null terminator character
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

// [string join (concatenate )] Takes two strings as input and concatenates them together into a new string.
// given s1 = *str, s2 = buffer
char	*ft_strjoin(char *s1, char *s2)
{
	size_t		i;
	size_t		j;
	char		*catstr;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	catstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!catstr)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[i] != '\0')
		{
			catstr[i] = s1[i];
			i++;
		}
	while (s2[j] != '\0')
		catstr[i++] = s2[j++];
	catstr[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (catstr);
}
