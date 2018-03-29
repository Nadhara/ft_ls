/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:51:06 by apruvost          #+#    #+#             */
/*   Updated: 2017/11/22 14:27:51 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dp;
	const unsigned char	*sp;
	size_t				i;

	dp = (unsigned char *)dst;
	sp = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dp[i] = sp[i];
		if (sp[i] == (unsigned char)c)
			return (&dp[i + 1]);
		i++;
	}
	return (NULL);
}
