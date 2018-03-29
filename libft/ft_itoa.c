/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:35:09 by apruvost          #+#    #+#             */
/*   Updated: 2017/11/22 12:51:48 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		numsize(int n)
{
	int		size;

	size = 0;
	if (n < 0)
		size++;
	while (n)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		neg;
	char	nbr;
	int		i;

	neg = 0;
	i = 0;
	if ((str = ft_strnew(numsize(n))) == NULL)
		return (NULL);
	if (n < 0)
		neg++;
	if (n == 0)
		return (ft_strdup("0"));
	while (n != 0)
	{
		nbr = (neg) ? (-1 * (n % 10)) + 48 : (n % 10) + 48;
		str[i] = nbr;
		n /= 10;
		i++;
	}
	if (neg)
		str[i] = '-';
	return (ft_strrev(str));
}
