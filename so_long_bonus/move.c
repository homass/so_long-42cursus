/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:56:46 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/01/07 18:28:30 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_rander(char **images)
{
	static int	i;
	char		*tmp[10];

	tmp[0] = "./textures/a.xpm";
	tmp[1] = "./textures/b.xpm";
	tmp[2] = "./textures/c.xpm";
	tmp[3] = "./textures/d.xpm";
	tmp[4] = "./textures/e.xpm";
	tmp[5] = "./textures/f.xpm";
	tmp[6] = "./textures/g.xpm";
	tmp[7] = "./textures/h.xpm";
	tmp[8] = "./textures/i.xpm";
	tmp[9] = "./textures/j.xpm";
	if (i == 10)
		i = 0;
	*images = tmp[i];
		i++;
}

void	render_m(t_so_long1 *var)
{
	static unsigned long long	m;
	static unsigned long long	r;

	r = ft_rand(var->px + var->py + (m / 2));
	if (m % 1500 == 0)
	{
		mlx_clear_window(var->mlx_ptr, var->win_ptr);
		ft_move_m(var, r);
		ft_render_frame_backround(var);
		ft_render_frame_ecp(var);
	}
	m++;
	if (m == 9000000000000000000)
		m = 0;
}

int	move(t_so_long1 *var)
{
	static unsigned long long	k;
	char						*images;

	if (k % 800 == 0)
	{
		mlx_clear_window(var->mlx_ptr, var->win_ptr);
		ft_rander(&images);
		mlx_clear_window(var->mlx_ptr, var->win_ptr);
		var->pointerc = mlx_xpm_file_to_image(var->mlx_ptr,
				images, &var->width, &var->height);
		ft_render_frame_backround(var);
		ft_render_frame_ecp(var);
	}
	render_m(var);
	k++;
	if (k == 9000000000000000000)
		k = 0;
	return (1);
}
