/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 14:42:32 by apruvost          #+#    #+#             */
/*   Updated: 2018/03/07 13:41:12 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void static		ft_arg(char *str, va_list ap)
{
	if (str[0] == 's')
		ft_putstr((const char*)va_arg(ap, char*));
	else if (str[0] == 'd')
		ft_putnbr(va_arg(ap, int));
	else if (str[0] == 'c')
		ft_putchar((unsigned char)va_arg(ap, int));
}

int				ft_printf(const char * restrict format, ...)
{
	int			i;
	va_list		ap;

	va_start(ap, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			write(1, &format[i], 1);
		else
			ft_arg((char*)&format[++i], ap);
		i++;
	}
	va_end(ap);
	return (0);
}