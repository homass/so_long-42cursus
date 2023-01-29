/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_ecp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:41:12 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/01/03 17:25:45 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_other_cha(char **tmp, t_so_long1 *var)
{
	t_var	vr;

	vr.i = 0;
	while (tmp[vr.i])
	{
		vr.j = 0;
		while (tmp[vr.i][vr.j] && tmp[vr.i][vr.j] != '\n')
		{
			if (tmp[vr.i][vr.j] != 'E' && tmp[vr.i][vr.j] != 'P'
				&& tmp[vr.i][vr.j] != 'C' && tmp[vr.i][vr.j] != '1'
					&& tmp[vr.i][vr.j] != '0')
			{
				ft_printf("THERE IS AN INCORRECT CHARACTER IN THE MAP!");
				ft_free_memory(var->map);
				exit(0);
			}
			vr.j++;
		}
		vr.i++;
	}
}

void	ft_check_map_ecp_plus(t_var *vr, char **tmp, int *i, int *j)
{
	if (tmp[*i][*j] == 'E')
		vr->e++;
	if (tmp[*i][*j] == 'C')
		vr->c++;
	if (tmp[*i][*j] == 'P')
		vr->p++;
}

void	ft_check_map_ecp(char **tmp, t_so_long1 *var)
{
	t_var	vr;

	vr.e = 0;
	vr.c = 0;
	vr.p = 0;
	vr.i = 0;
	while (tmp[vr.i])
	{
		vr.j = 0;
		while (tmp[vr.i][vr.j] && tmp[vr.i][vr.j] != '\n')
		{
			ft_check_map_ecp_plus(&vr, tmp, &vr.i, &vr.j);
			vr.j++;
		}
		vr.i++;
	}
	ft_check_other_cha(tmp, var);
	if (!(vr.e == 1 && vr.p == 1 && vr.c >= 1))
	{
		ft_printf("MAP 'E'C'P' ERROR");
		ft_free_memory(var->map);
		exit(0);
	}
}
