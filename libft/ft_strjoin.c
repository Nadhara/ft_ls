/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:07:04 by apruvost          #+#    #+#             */
/*   Updated: 2018/03/22 10:40:34 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;

	ft_printf("Go strjoin\n");
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		if ((str = (char *)malloc(len + 1)) == NULL)
			return (NULL);
		len = 0;
		while (*s1)
		{
			str[len] = (char)*s1;
			s1++;
			len++;
		}
		while (*s2)
		{
			str[len] = (char)*s2;
			s2++;
			len++;
		}
		str[len] = '\0';
		return (str);
	}
	return (NULL);
}
