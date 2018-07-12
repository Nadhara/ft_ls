/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getspeperm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 15:19:15 by apruvost          #+#    #+#             */
/*   Updated: 2018/07/12 15:25:42 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_getspeperm(mode_t mode, char *str)
{
	if ((mode & S_ISUID) == S_ISUID)
	{
		if (str[2] == 'x')
			str[2] = 's';
		else
			str[2] = 'S';
	}
	if ((mode & S_ISGID) == S_ISGID)
	{
		if (str[5] == 'x')
			str[5] = 's';
		else
			str[5] = 'S';
	}
	if ((mode & S_ISVTX) == S_ISVTX)
	{
		if (str[8] == 'x')
			str[8] = 't';
		else	
			str[8] = 'T';
	}
}