/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_frame_backround.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:40:53 by hait-hsa          #+#    #+#             */
/*   Updated: 2022/12/31 12:28:59 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_frame_backround(t_so_long1 *var)
{
	var->c = 0;
	while (var->r[var->c])
	{
		var->x = 0;
		while (var->r[var->c][var->x])
		{
			mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
				var->pointer, var->x * 100, var->c * 100);
			var->x++;
		}
		var->c++;
	}
}
