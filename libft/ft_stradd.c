/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:40:43 by apruvost          #+#    #+#             */
/*   Updated: 2017/11/17 16:06:04 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stradd(char *str, char c)
{
	size_t	len;
	char	*s2;
	char	*olds;
	size_t	i;

	olds = str;
	i = 0;
	if (olds == NULL || olds[0] == 0)
		len = 0;
	else
		len = ft_strlen(str);
	if ((s2 = (char *)malloc(len + 2)) == NULL)
		return (NULL);
	while (i < len)
	{
		s2[i] = olds[i];
		i++;
	}
	free(olds);
	s2[len] = c;
	s2[len + 1] = '\0';
	return (s2);
}
