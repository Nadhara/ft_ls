/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:06:23 by apruvost          #+#    #+#             */
/*   Updated: 2017/11/21 09:37:00 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lenght;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)haystack;
	lenght = ft_strlen(needle);
	if (*needle == 0)
		return (str);
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] && needle[j] && str[i + j] == needle[j]
				&& (i + j) < len)
			j++;
		if (!needle[j])
			return (&str[i]);
		i++;
	}
	return (NULL);
}
