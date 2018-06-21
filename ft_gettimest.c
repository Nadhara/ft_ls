/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettimest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 15:03:52 by apruvost          #+#    #+#             */
/*   Updated: 2018/06/21 15:31:57 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_normaltime(t_file *file)
{
	file->mtime[16] = '\0';
	if ((file->mtimechr = strdup(&(file->mtime[4]))) == NULL)
		file->mtimechr = 
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