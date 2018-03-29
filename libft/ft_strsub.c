/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:30:46 by apruvost          #+#    #+#             */
/*   Updated: 2017/11/19 17:02:30 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (s)
	{
		i = 0;
		if ((str = (char *)malloc(len + 1)) == NULL)
			return (NULL);
		str = ft_strncpy(str, &s[start], len);
		str[len] = '\0';
		return (str);
	}
	return (NULL);
}
