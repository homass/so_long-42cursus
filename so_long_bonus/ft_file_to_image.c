/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_to_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:57:59 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/01/07 18:34:40 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_file_to_image(t_so_long1 *var)
{
	mlx_clear_window(var->mlx_ptr, var->win_ptr);
	var->mlx_ptr = mlx_init();
	var->win_ptr = mlx_new_window(var->mlx_ptr, var->windowy * 100,
			var->windowx * 100, "so_long");
	var->pointer = mlx_xpm_file_to_image(var->mlx_ptr,
			"./textures/ground.xpm", &var->width, &var->height);
	var->pointer1 = mlx_xpm_file_to_image(var->mlx_ptr,
			"./textures/wall.xpm", &var->width, &var->height);
	var->pointerp = mlx_xpm_file_to_image(var->mlx_ptr,
			"./textures/frame1.xpm", &var->width, &var->height);
	var->pointere = mlx_xpm_file_to_image(var->mlx_ptr,
			"./textures/exit.xpm", &var->width, &var->height);
	var->pointerc = mlx_xpm_file_to_image(var->mlx_ptr,
			"./textures/a.xpm", &var->width, &var->height);
	var->pointerm = mlx_xpm_file_to_image(var->mlx_ptr,
			"./textures/mn.xpm", &var->width, &var->height);
}
