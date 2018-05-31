/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmaxs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 13:04:46 by apruvost          #+#    #+#             */
/*   Updated: 2018/05/31 10:38:52 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_getmaxsl(t_file *start_file, t_default *wep, t_arg arg)
{
	t_file	*file;

	file = start_file;
	wep->maxlk = 0;
	wep->maxsz = 0;
	wep->maxuslen = 0;
	wep->maxgrplen = 0;
	while (file != NULL)
	{
		if (!(file->name[0] == '.' && arg.arg_a_ == FALSE)
				&& file->isdata != 0)
		{
			if (file->stats->st_size > wep->maxsz)
				wep->maxsz = file->stats->st_size;
			if (file->stats->st_nlink > (unsigned int)wep->maxlk)
				wep->maxlk = file->stats->st_nlink;
			if (ft_strlen(file->nuser->pw_name) > wep->maxuslen)
				wep->maxuslen = ft_strlen(file->nuser->pw_name);
			if (ft_strlen(file->ngroup->gr_name) > wep->maxgrplen)
				wep->maxgrplen = ft_strlen(file->ngroup->gr_name);
		}
		file = file->next;
	}
	wep->maxlklen = ft_getintlen(wep->maxlk);
	wep->maxszlen = ft_getlonglen(wep->maxsz);
}

int			ft_getblktot(t_file *start_file, t_arg arg)
{
	t_file	*file;
	int		tot;

	file = start_file;
	tot = 0;
	while (file != NULL)
	{
		if (!(file->name[0] == '.' && arg.arg_a_ == FALSE))
		{
			tot += file->stats->st_blocks;
		}
		file = file->next;
	}
	return (tot);
}