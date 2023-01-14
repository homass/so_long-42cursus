/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:41:03 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/01/02 19:28:38 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_exit_plus(char **map, int i, int j, int *g)
{
	if (map[i][j] == 'E' && map[i][j + 1] != 'P')
		*g -= 1;
	if (map[i][j] == 'E' && map[i][j - 1] != 'P')
		*g -= 1;
	if (map[i][j] == 'E' && map[i - 1][j] != 'P')
		*g -= 1;
	if (map[i][j] == 'E' && map[i + 1][j] != 'P')
		*g -= 1;
}

void	ft_check_exit(char **map, t_so_long1 *var)
{
	static int	g;
	static int	i;
	static int	j;

	g = 4;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_check_exit_plus(map, i, j, &g);
			j++;
		}
		i++;
	}
	if (g == 0)
	{
		ft_printf("NO WAY TO REACH THE EXIT!");
		ft_free_memory(var->map);
		exit(0);
	}
}

void	ft_check_map_ecp_removed(char **map, t_so_long1 *var)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				ft_printf("NO WAY TO REACH THE COIN!");
				ft_free_memory(var->map);
				exit(0);
			}
			ft_check_exit(map, var);
			j++;
		}
		i++;
	}
}

void	helper(char **tmp, int i, int j, int *w)
{
	if (tmp[i][j + 1] != '1' && tmp[i][j + 1] != 'P' && tmp[i][j + 1] != 'E')
	{
		tmp[i][j + 1] = 'P';
		*w = 1;
	}
	if (tmp[i][j - 1] != '1' && tmp[i][j - 1] != 'P' && tmp[i][j - 1] != 'E')
	{
		tmp[i][j - 1] = 'P';
		*w = 1;
	}
	if (tmp[i - 1][j] != '1' && tmp[i - 1][j] != 'P' && tmp[i - 1][j] != 'E')
	{
		tmp[i - 1][j] = 'P';
		*w = 1;
	}
	if (tmp[i + 1][j] != '1' && tmp[i + 1][j] != 'P' && tmp[i + 1][j] != 'E')
	{
		tmp[i + 1][j] = 'P';
		*w = 1;
	}
}

int	ft_check_walls(char **tmp, t_so_long1 *var)
{
	int	i;
	int	j;
	int	w;

	w = 1;
	while (w)
	{
		w = 0;
		i = 0;
		while (tmp[i])
		{
			j = 0;
			while (tmp[i][j])
			{
				if (tmp[i][j] == 'P')
					helper(tmp, i, j, &w);
				j++;
			}
			i++;
		}
	}
	ft_check_map_ecp_removed(tmp, var);
	return (1);
}
