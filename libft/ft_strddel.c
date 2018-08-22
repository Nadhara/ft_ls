/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strddel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:20:06 by apruvost          #+#    #+#             */
/*   Updated: 2018/08/22 12:31:48 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strddel(char **as, char **bs)
{
	if (as)
	{
		free(*as);
		*as = 0;
	}
	if (bs)
	{
		free(*as);
		*as = 0;
	}
}
