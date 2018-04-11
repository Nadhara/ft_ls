/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 06:53:13 by apruvost          #+#    #+#             */
/*   Updated: 2018/04/11 16:35:13 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_dismore(t_file *file)
{
				file->mtime[16] = '\0';
				ft_printf("%c%s  %d %s  %s  %d %s %s\n",file->type, file->perms,
									file->stats->st_nlink, file->nuser->pw_name,
									file->ngroup->gr_name, file->stats->st_size,
												&(file->mtime[4]), file->name);
}

void		ft_display(t_default rep, t_file *start_file, t_arg arg)
{
	t_file	*file;

	file = start_file;
	if (arg.d_showed > 1)
		ft_putchar('\n');
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
			ft_dismore(file);
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
			file->type == 'd' || file->isdata == 0))
		{
			arg->d_showed++;
			if (arg->arg_l_ == FALSE)
				ft_printf("%s\n",file->name);
			else
				ft_dismore(file);
		}
		file = file->next;
	}	
}