/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbsp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 14:19:13 by apruvost          #+#    #+#             */
/*   Updated: 2018/08/01 19:40:10 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_nbspl(t_file *file, t_default *wep)
{
	int		i;
	int		j;
	char	*str;

	i = wep->maxlklen - ft_getintlen(file->stats->st_nlink);
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

char		*ft_nbsps(t_file *file, t_default *wep)
{
	int		i;
	int		j;
	char	*str;

	i = wep->maxszlen - ft_getintlen(file->stats->st_size);
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

char		*ft_nbspu(t_file *file, t_default *wep)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = wep->maxuslen - ft_strlen(file->nuser);
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

char		*ft_nbspg(t_file *file, t_default *wep)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = wep->maxgrplen - ft_strlen(file->ngroup);
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
