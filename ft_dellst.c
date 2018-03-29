/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dellst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 07:47:08 by apruvost          #+#    #+#             */
/*   Updated: 2018/03/22 08:18:51 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_dellone(t_file **file)
{
	ft_strdel(&(*file)->name);
	ft_strdel(&(*file)->path);
	ft_strdel(&(*file)->perms);
	ft_memdel((void **)&(*file)->stats);
	ft_memdel((void **)&(*file)->lfstats);
	ft_memdel((void **)file);
	*file = NULL;
}

void		ft_dellst(t_file **start_file)
{
	if ((*start_file)->next != NULL)
		ft_dellst(&(*start_file)->next);
	ft_dellone(start_file);
}