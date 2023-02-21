/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:33:12 by hait-hsa          #+#    #+#             */
/*   Updated: 2022/11/07 16:03:42 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*arr;
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	m;

	k = -1;
	m = 0;
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (i + j == 0)
	{
		free(s1);
		return (0);
	}
	arr = malloc(i + j + 1);
	while (++k < i)
		arr[k] = s1[k];
	while (k < (i + j))
		arr[k++] = s2[m++];
	arr[k] = 0;
	free(s1);
	return (arr);
}

int	ft_check_new_line(char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}
