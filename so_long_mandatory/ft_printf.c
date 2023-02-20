/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:33:45 by hait-hsa          #+#    #+#             */
/*   Updated: 2022/12/31 15:14:28 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_input(va_list input, const char c)
{
	if (c == 'c')
		ft_putchar(va_arg(input, int));
	else if (c == 's')
		ft_putstr(va_arg(input, char *));
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(input, int));
	else
		ft_putchar(c);
}

void	ft_printf(const char *str, ...)
{
	va_list	input;
	int		i;

	i = 0;
	va_start(input, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_check_input(input, str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(input);
}
