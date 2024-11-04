/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draask <draask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 08:25:11 by draask            #+#    #+#             */
/*   Updated: 2024/11/02 15:02:21 by draask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*get_next_line(int fd)
{
	ssize_t	bytes_read;
	char	*line;
	char	c;
	size_t	i;
	size_t	capacity;

	capacity = BUFFER_SIZE;
	i = 0;
	if (capacity <= 2048)
		capacity = 2048;
	line = malloc(capacity + 1 * sizeof(char));
	if (!line)
		return (NULL);
	while (1)
	{
		if (i >= capacity)
			line = morealloc(line, &capacity);
		bytes_read = read(fd, &c, 1);
		if (bytes_read == -1)
		{
			free(line);
			return (NULL);
		}
		if (bytes_read == 0)
		{
			if (i == 0)
			{
				free(line);
				return (NULL);
			}
			break ;
		}
		line[i++] = c;
		if (c == '\n')
			break ;
	}
	line[i] = '\0';
	return (line);
}

//int	main()
//{
//	int fd;
//	char *line;
//	//int i;

//	//i = 0;
//	fd = open("empty.txt", O_RDONLY);
//	if (fd == -1)
//		return (0);
//	line = get_next_line(fd);
//	printf("<%s>", line);
//	free(line);
//	line = get_next_line(fd);
//	//while (i < 18)
//	//{
//	//	line = get_next_line(fd);
//	printf("<%s>", line);
//	free(line);
//	//	i++;
//	//}
//	printf("\n");
//	close(fd);
//	//line = get_next_line(0);
//	return 0;
//}
