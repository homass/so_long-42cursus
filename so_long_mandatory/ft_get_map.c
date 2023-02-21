/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:08:50 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/01/03 18:37:51 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_read(char *tmp, t_so_long1 *var)
{
	int		fd;

	var->ii = 1;
	var->k = 0;
	var->buffer = malloc(1);
	if (!var->buffer)
		exit(0);
	fd = open(tmp, O_RDONLY, 777);
	while (var->ii)
	{
		var->ii = read(fd, var->buffer, 1);
		var->buffer[var->ii] = 0;
		if (var->ii < 0)
		{
			free(var->buffer);
			break ;
		}
		if (var->buffer[0] == '\n')
			var->k++;
	}
	free(var->buffer);
	close(fd);
	return (var->k + 1);
}

char	**ft_get_map(int fd, char *holder, t_so_long1 *var)
{
	int		i;
	char	**tmp;
	int		c;

	c = 0;
	i = ft_check_read(holder, var);
	tmp = malloc(sizeof(char *) * i);
	if (!tmp)
		exit(0);
	while (1)
	{
		tmp[c] = get_next_line(fd);
		if (!tmp[c])
			break ;
		c++;
	}
	tmp[c] = NULL;
	close(fd);
	return (tmp);
}
