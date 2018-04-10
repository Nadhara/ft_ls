/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:30:46 by apruvost          #+#    #+#             */
/*   Updated: 2018/04/05 08:48:04 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (s)
	{
		if ((str = (char *)malloc(len + 1)) == NULL)
			return (NULL);
		str = ft_strncpy(str, &s[start], len);
		str[len] = '\0';
		return (str);
	}
	return (NULL);
}
