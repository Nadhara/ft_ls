/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbsptwo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 18:59:54 by apruvost          #+#    #+#             */
/*   Updated: 2018/08/01 19:43:01 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_nbspmaj(t_file *file, t_default *wep)
{
	int		i;
	int		j;
	char	*str;

	i = wep->maxmajlen - ft_getintlen(major(file->stats->st_rdev));
	j = 0;
	if ((str = (char *)malloc(sizeof(char) * i + 1)) == NULL)
		return ("");
	while (j < i)
	{
		str[j] = ' ';
		j++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_nbspmin(t_file *file, t_default *wep)
{
	int		i;
	int		j;
	char	*str;

	i = wep->maxminlen - ft_getintlen(minor(file->stats->st_rdev));
	j = 0;
	if ((str = (char *)malloc(sizeof(char) * i + 1)) == NULL)
		return ("");
	while (j < i)
	{
		str[j] = ' ';
		j++;
	}
	str[i] = '\0';
	return (str);
}
