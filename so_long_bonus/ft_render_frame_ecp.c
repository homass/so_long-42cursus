/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_frame_ecp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:40:50 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/01/07 16:31:47 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_rander_frame_ecp_plus(t_so_long1 *var)
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
	mlx_clear_window(var->mlx_ptr, var->win_ptr);
	var->c = 0;
	while (var->r[var->c])
	{
		var->x = 0;
		while (var->r[var->c][var->x])
		{
			ft_rander_frame_ecp_plus(var);
			if (var->r[var->c][var->x] == '1')
				mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
					var->pointer1, var->x * 100, var->c * 100);
			if (var->r[var->c][var->x] == 'E')
				mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
					var->pointere, var->x * 100, var->c * 100);
			if (var->r[var->c][var->x] == 'M')
			{
				mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
					var->pointerm, var->x * 100, var->c * 100);
			}
			var->x++;
		}
		var->c++;
	}
	mlx_string_put(var->mlx_ptr, var->win_ptr, 10, 10, 0xff0000, "Step N:");
	mlx_string_put(var->mlx_ptr, var->win_ptr, 80, 10, 0xffffff, var->movement);
}
