/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draask <draask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:24:09 by draask            #+#    #+#             */
/*   Updated: 2024/11/03 11:01:42 by draask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <ctype.h>
# include <fcntl.h>

//# define BUFFER_SIZE 2048

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*morealloc(char *line, size_t *capacity);
size_t	ft_strlen(const char *str);
void	*ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t elementCount, size_t elementSize);

#endif 