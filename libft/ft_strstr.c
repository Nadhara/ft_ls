/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:42:26 by apruvost          #+#    #+#             */
/*   Updated: 2017/11/21 09:28:50 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)haystack;
	len = ft_strlen(needle);
	if (*needle == 0)
		return (str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] && needle[j] && str[i + j] == (char)needle[j])
			j++;
		if (!needle[j])
			return (&str[i]);
		i++;
	}
	return (NULL);
}
