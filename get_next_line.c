/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 08:25:11 by draask            #+#    #+#             */
/*   Updated: 2024/11/14 11:37:38 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*gtl(char *line, char *buffer)
{
	int		i;
	int		j;
	char	*rsltline;

	i = 0;
	j = 0;
	rsltline = ft_calloc((ft_strlen(line) + ft_strlen(buffer) + 2), 1);
	if (rsltline == NULL)
		return (free(line), NULL);
	if (line[0] != 0)
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
	return (rsltline[i + ++j] = '\0', free(line), rsltline);
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
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	bytes_read = 1;
	line = malloc(1);
	line[0] = 0;
	if (BUFFER_SIZE < 0)
		return (free(line), NULL);
	while (bytes_read != 0 && ft_strchr(line, '\n') == NULL)
	{
		if (buffer[0] == 0)
			bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(line), NULL);
		if (bytes_read == 0)
			break ;
		line = gtl(line, buffer);
		if (line == NULL)
			return (NULL);
		rstb(buffer, BUFFER_SIZE + 1);
	}
	if (bytes_read == 0 && buffer[0] == 0 && line[0] == 0)
		return (free(line), NULL);
	return (line);
}

//int	main()
//{
//	int fd;
//	char *line;
//	fd = open("./files/empty", O_RDONLY);
//	if (fd == -1)
//		return (0);
//	line = get_next_line(fd);
//	printf("%s", line);
//	free(line);

//	line = get_next_line(fd);
//	printf("%s", line);
//	if (line != NULL)
//		free(line);

//	line = get_next_line(fd);
//	printf("%s", line);
//	if (line != NULL)
//		free(line);

//	line = get_next_line(fd);
//	printf("%s", line);
//	if (line != NULL)
//		free(line);

//	line = get_next_line(fd);
//	printf("%s\n", line);
//	if (line != NULL)
//		free(line);

//	//line = get_next_line(fd);
//	//printf("%s", line);
//	//if (line != NULL)
//	//	free(line);

//	//close(fd);
//	return 0;
//}
