/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:30:49 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/01/07 14:52:09 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_numb(long int n)
{
	long int	i;

	i = 1;
	while (1)
	{
		if (n < 0)
		{
			i++;
			n *= -1;
		}
		n = n / 10;
		if (n)
			i++;
		else
			break ;
	}
	return (i);
}

char	*ft_itoa(long int cast)
{
	long int			i;
	long int			x;
	char				*arr;

	x = 0;
	i = ft_check_numb(cast);
	arr = malloc(((sizeof(char) * i) + 1));
	if (!arr)
		return (NULL);
	if (cast < 0)
	{
		arr[0] = '-';
		cast *= -1;
		x = 1;
	}
	arr[i] = 0;
	i--;
	while (i >= x)
	{
		arr[i--] = (cast % 10) + 48;
		cast = cast / 10;
	}
	return (arr);
}

//push
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred_numb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:56:30 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/01/31 18:57:24 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

int helper(t_list *st_a, int c)
{
	int i;

	i = 0;
	while(st_a)
	{
		if(st_a->data == c)
			return 1;
		st_a = st_a->link;
	}
	return 0;
}

int *get_first_smallest_numbs(t_list *st_a)
{
	static int counter;
	int *arr;
	int c;
	int first;
	int i;

	i = 0;
	arr = malloc(sizeof(int) * 20);
	first = get_first_smaller_numb(st_a);
	arr[counter] = first;
	c = first;
	counter++;
	while(counter < 20)
	{
		c++;
		if(helper(st_a, c))
			{
				arr[counter] = c;
				counter++;
			}
	}
	return arr;
}

void hundred_numb(t_list **st_a, t_list **st_b)
{
	int i;
	int *arr;

	i = 0;
	arr = get_first_smallest_numbs(*st_a);
	
}
