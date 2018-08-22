/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlonglen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:38:52 by apruvost          #+#    #+#             */
/*   Updated: 2018/08/01 19:37:08 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_getlonglen(long n)
{
	int		size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		size++;
	while (n)
	{
		size++;
		n /= 10;
	}
	return (size);
}
