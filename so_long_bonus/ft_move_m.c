/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_m.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:42:16 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/01/07 16:38:35 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_m_lift(t_so_long1 *var)
{
	mlx_clear_window(var->mlx_ptr, var->win_ptr);
	if ((var->r[var->my][var->mx - 1] == '0'
		|| var->r[var->my][var->mx - 1] == 'P'))
	{
		if (var->r[var->my][var->mx - 1] == 'P')
		{
			ft_free_memory(var->r);
			exit(0);
		}
		var->r[var->my][var->mx] = '0';
		var->r[var->my][var->mx - 1] = 'M';
	}
}

void	ft_move_m_right(t_so_long1 *var)
{
	mlx_clear_window(var->mlx_ptr, var->win_ptr);
	if ((var->r[var->my][var->mx + 1] == '0'
		|| var->r[var->my][var->mx + 1] == 'P'))
	{
		if (var->r[var->my][var->mx + 1] == 'P')
		{
			ft_free_memory(var->r);
			exit(0);
		}
		var->r[var->my][var->mx] = '0';
		var->r[var->my][var->mx + 1] = 'M';
	}
}

void	ft_move_m_down(t_so_long1 *var)
{
	mlx_clear_window(var->mlx_ptr, var->win_ptr);
	if ((var->r[var->my + 1][var->mx] == '0'
		|| var->r[var->my + 1][var->mx] == 'P'))
	{
		if (var->r[var->my + 1][var->mx] == 'P')
		{
			ft_free_memory(var->r);
			exit(0);
		}
		var->r[var->my][var->mx] = '0';
		var->r[var->my + 1][var->mx] = 'M';
	}
}

void	ft_move_m_up(t_so_long1 *var)
{
	mlx_clear_window(var->mlx_ptr, var->win_ptr);
	if (var->r[var->my - 1][var->mx] == '0'
		|| var->r[var->my - 1][var->mx] == 'P')
	{
		if (var->r[var->my - 1][var->mx] == 'P')
		{
			ft_free_memory(var->r);
			exit(0);
		}
		var->r[var->my][var->mx] = '0';
		var->r[var->my - 1][var->mx] = 'M';
	}
}

void	ft_move_m(t_so_long1 *var, unsigned long long r)
{
	mlx_clear_window(var->mlx_ptr, var->win_ptr);
	var->my = 0;
	var->mx = 0;
	while (var->r[var->my])
	{
		var->mx = 0;
		while (var->r[var->my][var->mx])
		{
			if (var->r[var->my][var->mx] == 'M')
			{
				if (r == 1)
					ft_move_m_up(var);
				else if (r == 9)
					ft_move_m_down(var);
				else if (r == 3)
					ft_move_m_right(var);
				else if (r == 6)
					ft_move_m_lift(var);
			}
			var->mx++;
		}
		var->my++;
	}
}
