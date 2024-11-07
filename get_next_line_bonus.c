/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 08:25:11 by draask            #+#    #+#             */
/*   Updated: 2024/11/07 18:02:28 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*gtl(char *line, char *buffer)
{
	int		i;
	int		j;
	char	*rsltline;

	i = 0;
	j = 0;
	rsltline = ft_calloc((ft_strlen(line) + ft_strlen(buffer) + 2), 1);
	if (line != NULL)
	{
		while (line[i] != '\0')
		{
			rsltline[i] = line[i];
			i++;
		}
	}
	while (buffer[j] != '\n' && buffer[j] != '\0')
	{
		rsltline[i + j] = buffer[j];
		j++;
	}
	if (buffer[j] == '\n')
		rsltline[i + j] = buffer[j];
	rsltline[i + ++j] = '\0';
	return (free(line), rsltline);
}

void	rstb(char *buffer, int size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (ft_strchr(buffer, '\n') == NULL)
		ft_bzero(buffer, size);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	while (buffer[i])
	{
		buffer[j] = buffer[i];
		j++;
		i++;
	}
	ft_bzero(&buffer[j], size - j);
}

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	bytes_read = 1;
	line = NULL;
	while (bytes_read != 0 && ft_strchr(buffer[fd], '\n') == NULL)
	{
		if (buffer[fd][0] == 0)
			bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		if (bytes_read == 0)
			break ;
		line = gtl(line, buffer[fd]);
		rstb(buffer[fd], BUFFER_SIZE + 1);
		if (ft_strchr(line, '\n') != NULL)
			return (line);
	}
	if (bytes_read == 0 && buffer[fd][0] == 0)
		if (line == NULL)
			return (NULL);
	line = gtl(line, buffer[fd]);
	rstb(buffer[fd], BUFFER_SIZE + 1);
	return (line);
}

//int	main()
//{
//	int fd;
//	int fd2;
//	char *line;

//	fd = open("lines_around_10.txt", O_RDONLY);
//	fd2 = open("read_error.txt", O_RDONLY);
//	if (fd == -1)
//		return (0);
//	line = get_next_line(fd);
//	printf("<%s", line);
//	free(line);

//	line = get_next_line(fd2);
//	printf("<%s", line);
//	if (line != NULL)
//		free(line);

//	line = get_next_line(fd);
//	printf("<%s", line);
//	if (line != NULL)
//		free(line);

//	line = get_next_line(fd2);
//	printf("<%s", line);
//	if (line != NULL)
//		free(line);

//	line = get_next_line(fd);
//	printf("<%s", line);
//	if (line != NULL)
//		free(line);

//	line = get_next_line(fd2);
//	printf("<%s", line);
//	if (line != NULL)
//		free(line);

//	line = get_next_line(fd);
//	printf("<%s", line);
//	if (line != NULL)
//		free(line);

//	line = get_next_line(fd2);
//	printf("<%s", line);
//	if (line != NULL)
//		free(line);

//	line = get_next_line(fd);
//	printf("<%s", line);
//	if (line != NULL)
//		free(line);

//	line = get_next_line(fd2);
//	printf("<%s", line);
//	if (line != NULL)
//		free(line);

//	close(fd);
//	return 0;
//}
