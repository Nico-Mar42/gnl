/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 08:17:50 by draask            #+#    #+#             */
/*   Updated: 2024/11/12 10:22:23 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//#define malloc(...) NULL

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	while (*s)
	{
		if (*s == uc)
			return ((char *)s);
		s++;
	}
	if (uc == '\0')
		return ((char *)s);
	return (NULL);
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

void	ft_bzero(void *str, size_t n)
{
	char	*s;

	s = str;
	while (n != 0)
	{
		*s = 0;
		s++;
		n--;
	}
}
