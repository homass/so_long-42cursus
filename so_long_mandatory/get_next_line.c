/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:57:03 by hait-hsa          #+#    #+#             */
/*   Updated: 2022/12/31 12:23:48 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_after_new_line(char *container)
{
	char	*arr;
	size_t	i;
	size_t	j;
	size_t	m;
	size_t	f;

	m = 0;
	i = 0;
	j = ft_strlen(container);
	while (container && container[i] && container[i] != '\n')
		i++;
	if (!container || !container[i] || (container[i] == '\n'
			&& container[i + 1] == '\0'))
	{
		free(container);
		return (NULL);
	}
	i++;
	f = i;
	arr = malloc((j - i) + 1);
	while (m < j - i)
		arr[m++] = container[f++];
	arr[m] = 0;
	free(container);
	return (arr);
}

char	*get_befor_new_line(char *container)
{
	char	*arr;
	size_t	i;
	size_t	j;

	if (!container)
		return (NULL);
	i = 0;
	j = 0;
	while (container[i] && container[i] != '\n')
		i++;
	if (container[i] == '\n')
		i++;
	arr = malloc(i + 1);
	if (!arr)
		return (NULL);
	while (j < i)
	{
		arr[j] = container[j];
		j++;
	}
	arr[j] = 0;
	return (arr);
}

char	*get_line_copy(int fd, char *container)
{
	char	*buffer;
	int		size;

	size = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (size > 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
		{
			free(container);
			free(buffer);
			return (0);
		}
		buffer[size] = 0;
		container = ft_strjoin(container, buffer);
		if (!ft_check_new_line(buffer))
			break ;
	}
	free(buffer);
	return (container);
}

char	*get_next_line(int fd)
{
	static char	*container;
	char		*holder;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!container)
	{
		container = malloc(1);
		if (!container)
			return (NULL);
		container[0] = '\0';
	}
	container = get_line_copy(fd, container);
	holder = get_befor_new_line(container);
	container = get_after_new_line(container);
	if (!holder)
	{
		free(container);
		return (NULL);
	}
	return (holder);
}
