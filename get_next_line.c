/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 08:25:11 by draask            #+#    #+#             */
/*   Updated: 2024/11/05 16:42:19 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_getline(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	line = malloc(i + 2 * 1);
	while (j != i + 1)
	{
		line[j] = buffer[j];
		j++;
	}
	line[j] = 0;
	return (line);
}

void	ft_restbuffer(char *buffer, int size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	i++;
	while (buffer[i])
	{
		buffer[j] = buffer[i];
		j++;
		i++;
	}
	while (j < size - 1)
	{
		buffer[j] = 0;
		j++;
	}

}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;
	int			i;

	i = -1;
	bytes_read = 1;
	while (bytes_read != 0 && ft_strchr(buffer, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		if (bytes_read == 0)
			break ;
		line = ft_getline(buffer);
		ft_restbuffer(buffer, BUFFER_SIZE + 1);
		while (line[++i] != '\0')
		{
			if (line[i] == '\n')
				return (line);
		}
	}
	if (bytes_read == 0 && buffer[0] == 0)
		return (line);
	line = ft_getline(buffer);
	ft_restbuffer(buffer, BUFFER_SIZE + 1);
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

//	//line = get_next_line(fd);
//	//printf("%s", line);
//	//if (line != NULL)
//	//	free(line);

//	//line = get_next_line(fd);
//	//printf("%s", line);
//	//if (line != NULL)
//	//	free(line);

//	//line = get_next_line(fd);
//	//printf("%s", line);
//	//if (line != NULL)
//	//	free(line);
//	close(fd);
//	return 0;
//}
