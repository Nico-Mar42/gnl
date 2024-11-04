/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draask <draask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 08:25:11 by draask            #+#    #+#             */
/*   Updated: 2024/11/04 23:25:14 by draask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*findrest(char *temp)
{
	char	*rest;
	int		i;
	int		j;

	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
		i++;
	rest = ft_calloc(ft_strlen(&temp[i]) + 1, 1);
	if (!rest)
		return (NULL);
	j = 0;
	while (temp[i + j] != '\0')
	{
		rest[j] = temp[i + j];
		j++;
	}
	rest[j] = '\0';

	return (rest);
}

char	*get_next_line(int fd)
{
	ssize_t		bytes_read;
	char		*line;
	char		*temp;
	static char	*rest = NULL;
	char		*temp_line;
	size_t		i;

	i = 0;
	bytes_read = 1;
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (NULL);

	line = ft_calloc(1, sizeof(char));
	if (!line)
	{
		free(temp);
		return (NULL);
	}
	if (rest)
	{
		temp_line = line;
		line = ft_strjoin(line, rest);
		free(temp_line);
		if (rest != NULL)
			free(rest);
		rest = NULL;
		if (!line)
		{
			free(temp);
			return (NULL);
		}
	}
	while (bytes_read > 0)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(line);
			free(temp);
			return (NULL);
		}
		temp[bytes_read] = '\0';
		temp_line = line;
		line = ft_strjoin(line, temp);
		free(temp_line);
		if (!line)
		{
			free(temp);
			return (NULL);
		}
		i = 0;
		while (line[i])
		{
			if (line[i] == '\n')
			{
				rest = findrest(temp);
				free(temp);
				return (line);
			}
			i++;
		}
	}
	if (line[0] == '\0')
	{
		free(line);
		line = NULL;
	}
	free(temp);
	return (line);
}

//int	main()
//{
//	int fd;
//	char *line;
//	fd = open("empty.txt", O_RDONLY);
//	if (fd == -1)
//		return (0);
//	line = get_next_line(fd);
//	printf("%s", line);
//	free(line);
//	line = get_next_line(fd);
//	printf("%s", line);
//	if (line != NULL)
//		free(line);
//	close(fd);
//	line = get_next_line(fd);
//	printf("%s", line);
//	if (line != NULL)
//		free(line);
//	close(fd);
//	line = get_next_line(fd);
//	printf("%s", line);
//	if (line != NULL)
//		free(line);
//	close(fd);
//	line = get_next_line(fd);
//	printf("%s", line);
//	if (line != NULL)
//		free(line);
//	close(fd);
//	line = get_next_line(fd);
//	printf("%s", line);
//	if (line != NULL)
//		free(line);
//	close(fd);
//	return 0;
//}
