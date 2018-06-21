/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dellst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 07:47:08 by apruvost          #+#    #+#             */
/*   Updated: 2018/06/01 15:19:30 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_dellone(t_file **file)
{
	ft_strdel(&(*file)->name);
	ft_strdel(&(*file)->path);
	if ((*file)->isdata != 0)
	{
		ft_memdel((void **)&(*file)->stats);
		ft_strdel(&(*file)->perms);
		ft_strdel(&(*file)->mtime);
		ft_strdel(&(*file)->nuser);
		ft_strdel(&(*file)->ngroup);
	} 
	ft_memdel((void **)file);
	*file = NULL;
}

void		ft_dellst(t_file **start_file)
{
	if ((*start_file)->next != NULL)
		ft_dellst(&(*start_file)->next);
	ft_dellone(start_file);
}