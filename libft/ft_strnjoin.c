/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:07:04 by apruvost          #+#    #+#             */
/*   Updated: 2018/01/10 13:03:41 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_stringtwo(const char *s2, char *str, size_t n, size_t *len)
{
	size_t		i;

	i = 0;
	while (*s2 && i < n)
	{
		str[*len] = (char)*s2;
		s2++;
		*len = *len + 1;
		i++;
	}
	return (str);
}

char			*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	size_t	len;
	char	*str;

	if (s1 && s2)
	{
		len = ft_strlen(s1);
		if (ft_strlen(s2) > n)
			len += n;
		else
			len += ft_strlen(s2);
		if ((str = (char *)malloc(len + 1)) == NULL)
			return (NULL);
		len = 0;
		while (*s1)
		{
			str[len] = (char)*s1;
			s1++;
			len++;
		}
		str = ft_stringtwo(s2, str, n, &len);
		str[len] = '\0';
		return (str);
	}
	return (NULL);
}
