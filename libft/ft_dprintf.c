/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:22:59 by apruvost          #+#    #+#             */
/*   Updated: 2018/08/01 19:36:39 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_arg(char *str, va_list ap, int fd)
{
	if (str[0] == 's')
		ft_putstr_fd((const char*)va_arg(ap, char*), fd);
	else if (str[0] == 'd')
		ft_putnbr_fd(va_arg(ap, int), fd);
	else if (str[0] == 'd')
		ft_putlong_fd(va_arg(ap, long), fd);
	else if (str[0] == 'c')
		ft_putchar_fd((unsigned char)va_arg(ap, int), fd);
}

int				ft_dprintf(int fd, const char *restrict format, ...)
{
	int			i;
	va_list		ap;

	va_start(ap, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			write(fd, &format[i], 1);
		else
			ft_arg((char*)&format[++i], ap, fd);
		i++;
	}
	va_end(ap);
	return (0);
}
