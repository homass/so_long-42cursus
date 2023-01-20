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
