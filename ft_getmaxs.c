/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmaxs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 13:04:46 by apruvost          #+#    #+#             */
/*   Updated: 2018/06/01 18:49:12 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_getmaxsm(t_file *file, t_default *wep)
{
	if (file->type == 'c' || file->type == 'b')
	{
		if (major(file->stats->st_rdev) > wep->maxmaj)
			wep->maxmaj = major(file->stats->st_rdev);
		if (minor(file->stats->st_rdev) > wep->maxmin)
			wep->maxmin = minor(file->stats->st_rdev);
	}
	else
	{
			if (file->stats->st_size > wep->maxsz)
				wep->maxsz = file->stats->st_size;
	}
}

static void	ft_initmax(t_default *wep)
{
	wep->maxlk = 0;
	wep->maxsz = 0;
	wep->maxuslen = 0;
	wep->maxgrplen = 0;
	wep->maxmaj = 0;
	wep->maxmin = 0;
	wep->maxmajlen = 0;
	wep->maxminlen = 0;
	wep->maxmajminlen = 0;
}

static void	ft_getgrsmajmin(t_default *wep)
{
	if (wep->maxszlen > wep->maxmajminlen)
		wep->maxmajminlen = wep->maxszlen;
	else
		wep->maxszlen = wep->maxmajminlen;
}

void		ft_getmaxsl(t_file *start_file, t_default *wep, t_arg arg)
{
	t_file	*file;

	file = start_file;
	ft_initmax(wep);
	while (file != NULL)
	{
		if (!(file->name[0] == '.' && arg.arg_a_ == FALSE)
				&& file->isdata != 0)
		{
			ft_getmaxsm(file, wep);
			if (file->stats->st_nlink > (unsigned int)wep->maxlk)
				wep->maxlk = file->stats->st_nlink;
			if (ft_strlen(file->nuser) > wep->maxuslen)
				wep->maxuslen = ft_strlen(file->nuser);
			if (ft_strlen(file->ngroup) > wep->maxgrplen)
				wep->maxgrplen = ft_strlen(file->ngroup);
		}
		file = file->next;
	}
	wep->maxlklen = ft_getintlen(wep->maxlk);
	wep->maxszlen = ft_getlonglen(wep->maxsz);
	wep->maxmajlen = ft_getintlen(wep->maxmaj);
	wep->maxminlen = ft_getintlen(wep->maxmin);
	wep->maxmajminlen = wep->maxmajlen + wep->maxminlen + 3;
	ft_getgrsmajmin(wep);
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