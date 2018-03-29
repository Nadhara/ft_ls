/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 06:53:13 by apruvost          #+#    #+#             */
/*   Updated: 2018/03/22 08:23:39 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_display(t_default rep, t_file *start_file, t_arg arg)
{
	t_file	*file;

	file = start_file;
	if (rep.shpth == TRUE)
		ft_printf("%s:\n", rep.path);
	if (arg.arg_l_ == TRUE)
		ft_printf("total %d\n", 42);
	while (file != NULL)
	{
		if (!(file->name[0] == '.' && arg.arg_a_ == FALSE))
		{
			if (arg.arg_l_ == FALSE)
				ft_printf("%s\n",file->name);
			else
			{
				file->mtime[19] = '\0';
				ft_printf("%s%s  %d %s  %s  %d %s %s",file->type, file->perms,
									file->stats->st_nlink, file->nuser->pw_name,
									file->ngroup->gr_name, file->stats->st_size,
												&(file->mtime[4]), file->name);
			}
		}
		file = file->next;
	}
}

void		ft_showfiles(t_arg *arg)
{
	t_file	*file;

	file = arg->args;
	while (file != NULL)
	{
		if (!((file->name[0] == '.' && arg->arg_a_ == FALSE) ||
			file->type == 'd'))
		{
			if (arg->arg_l_ == FALSE)
				ft_printf("%s\n",file->name);
			else
			{
				file->mtime[19] = '\0';
				ft_printf("%s%s  %d %s  %s  %d %s %s",file->type, file->perms,
									file->stats->st_nlink, file->nuser->pw_name,
									file->ngroup->gr_name, file->stats->st_size,
												&(file->mtime[4]), file->name);
			}
		}
		file = file->next;
	}	
}