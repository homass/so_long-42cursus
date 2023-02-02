/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:33:45 by hait-hsa          #+#    #+#             */
/*   Updated: 2022/12/31 11:32:14 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_input(va_list input, const char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(input, int));
	else if (c == 's')
		len += ft_putstr(va_arg(input, char *));
	else
		len += ft_putchar(c);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	input;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(input, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_check_input(input, str[i]);
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(input);
	return (len);
}
