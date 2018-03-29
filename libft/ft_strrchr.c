/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:29:42 by apruvost          #+#    #+#             */
/*   Updated: 2017/11/13 14:38:50 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;
	char		*str;
	long int	last;

	i = 0;
	str = (char *)s;
	last = -1;
	while (str[i])
	{
		if (str[i] == (char)c)
			last = i;
		i++;
	}
	if (c == 0)
		return (&str[i]);
	if (last == -1)
		return (NULL);
	else
		return (&str[last]);
}
