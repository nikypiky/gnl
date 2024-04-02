/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilar <nsilar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:49:50 by nsilar            #+#    #+#             */
/*   Updated: 2024/04/02 16:49:51 by nsilar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *c)
{
	size_t	i;

	i = 0;
	if (c)
	{
		while (c[i] != 0)
			i++;
	}
	return (i);
}

size_t	gnl_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (gnl_strlen(src));
	while (i <= size - 1 && src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (gnl_strlen(src));
}
