/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_inside.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:41:06 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/01/02 19:27:44 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_inside(char *tmp, t_so_long1 *int_v)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	if (tmp[0] != '1')
	{
		ft_printf("WALLS ERROR");
		ft_free_memory(int_v->map);
		exit(0);
	}
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i - 1] != '1')
	{
		ft_printf("WALLS ERROR");
		ft_free_memory(int_v->map);
		exit(0);
	}
}
