/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:16:49 by apruvost          #+#    #+#             */
/*   Updated: 2017/11/19 16:55:12 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	isblank_start(char const *s)
{
	size_t	size;

	size = 0;
	while (*s && (*s == ' ' || *s == '\n' || *s == '\t'))
	{
		size++;
		s++;
	}
	return (size);
}

static	size_t	isblank_end(char const *s)
{
	size_t	size;
	size_t	i;

	size = 0;
	i = ft_strlen(s) - 1;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
	{
		size++;
		i--;
	}
	return (size);
}

static	char	*assigval(char const *s, char *str, size_t i, size_t len)
{
	size_t	j;

	j = 0;
	while (j < len)
	{
		str[j] = (char)s[i + j];
		j++;
	}
	return (str);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	len;

	if (s)
	{
		if (ft_strlen(s) == isblank_start(s))
		{
			if ((str = ft_strnew(0)) == NULL)
				return (NULL);
			return (str);
		}
		len = ft_strlen(s) - (isblank_start(s) + isblank_end(s));
		if ((str = (char *)malloc(len + 1)) == NULL)
			return (NULL);
		i = isblank_start(s);
		str = assigval(s, str, i, len);
		str[len] = '\0';
		return (str);
	}
	return (NULL);
}
