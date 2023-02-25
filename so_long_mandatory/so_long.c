/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:40:27 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/01/03 18:38:18 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_window_size(t_so_long1 *var)
{
	while (var->r[var->windowx])
		var->windowx++;
	while (var->r[0][var->windowy])
		var->windowy++;
	var->windowy--;
}

void	count_coins(t_so_long1 *var)
{
	int	i;
	int	j;

	i = 0;
	while (var->r[i])
	{
		j = 0;
		while (var->r[i][j])
		{
			if (var->r[i][j] == 'C')
				var->allcoins++;
			j++;
		}
		i++;
	}
}

void	so_long(int fd, char *tmp)
{
	t_so_long1	int_v;

	int_v.i = 1;
	int_v.c = -1;
	fd = open(tmp, O_RDONLY, 777);
	int_v.map = ft_get_map(fd, tmp, &int_v);
	ft_check_strings_lent(&int_v);
	while (int_v.map[++int_v.c])
		ft_check_up_down(int_v.map[0], &int_v);
	ft_check_up_down(int_v.map[int_v.c - 1], &int_v);
	while (int_v.i < int_v.c - 1)
		ft_check_inside(int_v.map[int_v.i++], &int_v);
	ft_check_map_ecp(int_v.map, &int_v);
	ft_check_walls(int_v.map, &int_v);
	int_v.leaks = 0;
	while (int_v.map[int_v.leaks])
		free(int_v.map[int_v.leaks++]);
	free(int_v.map);
}

int	main(int arc, char **arv)
{
	t_so_long1	var;

	var.allcoins = 0;
	var.coin = 0;
	var.windowx = 0;
	var.windowy = 0;
	var.counter = 1;
	ft_check_ber(&var, arc, arv[1]);
	count_coins(&var);
	ft_window_size(&var);
	ft_file_to_image(&var);
	ft_render_frame_backround(&var);
	ft_render_frame_ecp(&var);
	mlx_hook(var.win_ptr, 2, 0, key_hook, &var);
	mlx_hook(var.win_ptr, 17, 0, exit_hook, &var);
	mlx_loop(var.mlx_ptr);
}
