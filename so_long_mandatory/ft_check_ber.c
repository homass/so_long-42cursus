/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:17:16 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/01/02 18:30:18 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map_name(char *tmp)
{
	char	*arr;
	int		i;
	int		j;

	arr = ".ber";
	j = 3;
	i = ft_strlen(tmp);
	i--;
	while (j >= 0)
	{
		if (tmp[i] != arr[j])
		{
			ft_printf("INVALID MAP NAME!");
			exit(0);
		}
		j--;
		i--;
	}
}

void	ft_check_ber(t_so_long1 *var, int arc, char *tmp)
{
	if (arc == 2 && tmp)
	{
		ft_check_map_name(tmp);
		new_map(var, tmp);
	}
	else
	{
		ft_printf("MAP NOT FOUND!");
		exit(0);
	}
}
