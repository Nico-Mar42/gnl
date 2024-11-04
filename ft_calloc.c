/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draask <draask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:08:30 by nicolmar          #+#    #+#             */
/*   Updated: 2024/10/19 12:29:32 by draask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"
#include <stdint.h>
#include <unistd.h>

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
