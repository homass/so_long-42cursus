/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ckeck_string_lent.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:07:41 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/01/02 19:28:50 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_strings_lent(t_so_long1 *var)
{
	int	i1;

	i1 = 0;
	while (var->map[i1] && var->map[i1 + 1])
	{
		if (ft_strlen(var->map[0]) - 1 != ft_strlen(var->map[i1]) - 1)
		{
			if (var->map[i1 + 1] == NULL)
				break ;
			else
			{
				ft_printf("WALLS ERROR!");
				ft_free_memory(var->map);
				exit(0);
			}
		}
		i1++;
	}
	if (ft_strlen(var->map[0]) - 1 != ft_strlen(var->map[i1]))
	{
		ft_printf("WALLS ERROR!");
		ft_free_memory(var->map);
		exit(0);
	}
}
