/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:40:42 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/01/02 18:58:36 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_down(t_so_long1 *var)
{
	if (var->r[var->py + 1][var->px] == 'E' && var->coin == var->allcoins)
	{
		ft_printf("YOU WIN :) !!\n");
		ft_free_memory(var->r);
		exit(0);
	}
	if (var->r[var->py + 1][var->px] == '0'
		|| var->r[var->py + 1][var->px] == 'C')
	{
		ft_printf("The Current Movemment: %d\n", var->counter++);
		if (var->r[var->py + 1][var->px] == 'C')
			var->coin++;
		var->r[var->py + 1][var->px] = 'P';
		var->r[var->py][var->px] = '0';
	}
}

void	ft_up(t_so_long1 *var)
{
	if (var->r[var->py - 1][var->px] == 'E' && var->coin == var->allcoins)
	{
		ft_printf("YOU WIN :) !!\n");
		ft_free_memory(var->r);
		exit(0);
	}
	if (var->r[var->py - 1][var->px] == '0'
		|| var->r[var->py - 1][var->px] == 'C')
	{
		ft_printf("The Current Movemment: %d\n", var->counter++);
		if (var->r[var->py - 1][var->px] == 'C')
			var->coin++;
		var->r[var->py - 1][var->px] = 'P';
		var->r[var->py][var->px] = '0';
	}
}

void	ft_left(t_so_long1 *var)
{
	var->pointerp = mlx_xpm_file_to_image(var->mlx_ptr,
			"./textures/frame1l.xpm", &var->width, &var->height);
	if (var->r[var->py][var->px - 1] == 'E' && var->coin == var->allcoins)
	{
		ft_printf("YOU WIN :) !!\n");
		ft_free_memory(var->r);
		exit(0);
	}
	if (var->r[var->py][var->px - 1] == '0'
		|| var->r[var->py][var->px - 1] == 'C')
	{
		ft_printf("The Current Movemment: %d\n", var->counter++);
		if (var->r[var->py][var->px - 1] == 'C')
			var->coin++;
		var->r[var->py][var->px - 1] = 'P';
		var->r[var->py][var->px] = '0';
	}
}

void	ft_right(t_so_long1 *var)
{
	var->pointerp = mlx_xpm_file_to_image(var->mlx_ptr,
			"./textures/frame1.xpm", &var->width, &var->height);
	if (var->r[var->py][var->px + 1] == 'E' && var->coin == var->allcoins)
	{
		ft_printf("YOU WIN :) !!\n");
		ft_free_memory(var->r);
		exit(0);
	}
	if (var->r[var->py][var->px + 1] == '0'
		|| var->r[var->py][var->px + 1] == 'C')
	{
		ft_printf("The Current Movemment: %d\n", var->counter++);
		if (var->r[var->py][var->px + 1] == 'C')
			var->coin++;
		var->r[var->py][var->px + 1] = 'P';
		var->r[var->py][var->px] = '0';
	}
}

int	key_hook(int keycode, t_so_long1 *var)
{
	if (keycode == 53)
		exit(0);
	mlx_clear_window(var->mlx_ptr, var->win_ptr);
	if (keycode == 2)
		ft_right(var);
	if (keycode == 0)
		ft_left(var);
	if (keycode == 13)
		ft_up(var);
	if (keycode == 1)
		ft_down(var);
	ft_render_frame_backround(var);
	ft_render_frame_ecp(var);
	return (0);
}
