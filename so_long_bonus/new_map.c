/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:56:49 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/01/07 14:30:13 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	new_map(t_so_long1 *var, char *tmp)
{
	int		fd;
	char	**r;

	fd = open(tmp, O_RDONLY, 777);
	if (fd < 0)
	{
		ft_printf("MAP NOT FOUND!");
		exit(0);
	}
	so_long(0, tmp);
	r = ft_get_map(fd, tmp, var);
	var->r = r;
}
