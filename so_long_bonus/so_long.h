/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:40:33 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/01/07 14:23:47 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx.h"
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct map_var{
	int	j;
	int	i;
	int	e;
	int	c;
	int	p;
	int	m;
}	t_var;

typedef struct so_long
{
	char				*image;
	int					i1;
	int					c1;
	int					leaks;
	char				**map;
	unsigned long long	counter;
	int					c;
	int					i;
	int					j;
	int					x;
	void				*mlx_ptr;
	void				*win_ptr;
	int					width;
	int					height;
	void				*pointer;
	void				*pointer1;
	void				*pointerp;
	void				*pointerc;
	void				*pointere;
	void				*pointerm;
	char				*ground;
	char				**r;
	int					px;
	int					py;
	int					coin;
	int					allcoins;
	int					windowx;
	int					windowy;
	int					my;
	int					mx;
	char				*movement;
	char				*buffer;
	int					k;
	int					ii;
}	t_so_long1;

int						move(t_so_long1 *var);
int						key_hook(int keycode, t_so_long1 *var);
void					so_long(int fd, char *tmp);
int						ft_check_walls(char **tmp, t_so_long1 *int_v);
void					ft_check_map_ecp(char **tmp, t_so_long1 *var);
void					ft_check_up_down(char *tmp, t_so_long1 *int_v);
void					ft_check_inside(char *tmp, t_so_long1 *int_v);
void					ft_render_frame_backround(t_so_long1 *var);
void					ft_render_frame_ecp(t_so_long1 *var);
void					ft_move_m(t_so_long1 *var, unsigned long long r);
void					ft_check_strings_lent(t_so_long1 *var);
char					**ft_get_map(int fd, char *tmp, t_so_long1 *var);
void					ft_file_to_image(t_so_long1 *var);
void					new_map(t_so_long1 *r, char *tmp);
char					*ft_itoa(long int cast);
void					ft_check_ber(t_so_long1 *var, int arc, char *tmp);
int						exit_hook(t_so_long1 *var);
void					ft_free_memory(char **tmp);
unsigned long long		ft_rand(unsigned long long x);
#endif