/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettimest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 15:03:52 by apruvost          #+#    #+#             */
/*   Updated: 2018/08/01 19:13:37 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_normaltime(t_file *file)
{
	file->mtime[16] = '\0';
	file->mtimechr = &(file->mtime[4]);
	file->timenorm = 1;
}

static void	ft_timewyear(t_file *file)
{
	char	*bin;
	int		i;
	int		y;

	file->mtime[11] = '\0';
	if ((bin = ft_strdup(&(file->mtime[4]))) == NULL)
		ft_exit(0, "");
	i = 19;
	while (file->mtime[i] == ' ')
		i++;
	y = i - 1;
	while (file->mtime[i] != '\0')
	{
		if (file->mtime[i] == '\n')
			file->mtime[i] = '\0';
		i++;
	}
	if ((file->mtimechr = ft_strjoin(bin, &(file->mtime[y]))) == NULL)
		ft_exit(0, "");
	ft_strdel(&bin);
	file->timenorm = 0;
}

void		ft_gettimest(t_file *file)
{
	time_t	curr_time;

	curr_time = time(NULL);
	if (file->fttime > curr_time)
		ft_timewyear(file);
	else if (curr_time - file->fttime > 15780000)
		ft_timewyear(file);
	else
		ft_normaltime(file);
}
