/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draask <draask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 08:17:50 by draask            #+#    #+#             */
/*   Updated: 2024/11/04 22:18:19 by draask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_bzero(void *str, size_t n )
{
	char	*s;

	if (str == NULL)
		return (NULL);
	s = str;
	while (n != 0)
	{
		*s = 0;
		s++;
		n--;
	}
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*data;

	if ((int)elementCount < 0 && (int)elementSize < 0)
		return (NULL);
	data = malloc(elementCount * elementSize);
	if (data == NULL)
		return (NULL);
	ft_bzero(data, elementCount * elementSize);
	return (data);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	dest = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j] && s2[j] != '\n')
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	if (s2[j] == '\n')
		dest[i++] = '\n';

	dest[i] = '\0';
	return (dest);
}


char	*morealloc(char *line, size_t *capacity)
{
	char	*temp;
	size_t	i;
	size_t	j;

	i = *capacity * 2;
	j = 0;
	temp = malloc((i + 2) * sizeof(char));
	if (!temp)
	{
		free(line);
		return (NULL);
	}
	*capacity = i;
	while (j < i / 2)
	{
		temp[j] = line[j];
		j++;
	}
	free(line);
	return (temp);
}
