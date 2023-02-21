/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_frame_ecp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:40:50 by hait-hsa          #+#    #+#             */
/*   Updated: 2022/12/31 17:04:28 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_frame_ecp_plus(t_so_long1 *var)
{
	if (var->r[var->c][var->x] == 'C')
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
			var->pointerc, var->x * 100, var->c * 100);
	if (var->r[var->c][var->x] == 'P')
	{
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
			var->pointerp, var->x * 100, var->c * 100);
		var->px = var->x;
		var->py = var->c;
	}
}

void	ft_render_frame_ecp(t_so_long1 *var)
{
	var->c = 0;
	while (var->r[var->c])
	{
		var->x = 0;
		while (var->r[var->c][var->x])
		{
			ft_render_frame_ecp_plus(var);
			if (var->r[var->c][var->x] == '1')
				mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
					var->pointer1, var->x * 100, var->c * 100);
			if (var->r[var->c][var->x] == 'E')
				mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
					var->pointere, var->x * 100, var->c * 100);
			var->x++;
		}
		var->c++;
	}
}
