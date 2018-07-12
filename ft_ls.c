/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 18:59:11 by apruvost          #+#    #+#             */
/*   Updated: 2018/07/12 18:50:53 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


static void		ft_readdir(t_file *file, t_arg *arg)
{
	while (file != NULL)
	{
		if (file->type == 'd')
		{
			if (arg->arg_a_ == TRUE)
			{
				if (ft_strcmp(file->name, ".") != 0 &&
					ft_strcmp(file->name, "..") != 0)
				{
					if (file->perms[2] != 'x' && file->perms[0] == 'r')
						ft_printf("%s%s:\n", (arg->d_showed > 1 ? "\n" : ""), file->path);	
					else
						ft_ls(file->path, arg, TRUE, file->name);
				}
			}
			else if (file->name[0] != '.')
			{
				if (file->perms[2] != 'x' && file->perms[0] == 'r')
					ft_printf("%s%s:\n", (arg->d_showed > 1 ? "\n" : ""), file->path);	
				else
				ft_ls(file->path, arg, TRUE, file->name);
			}
		}
		file = file->next;
	}
}

static void		ft_ctopdir(t_arg *arg, t_default rep, char *name)
{
		if (rep.shpth == TRUE)
			ft_printf("%s%s:\n", (arg->d_showed > 1 ? "\n" : ""), rep.path);
		ft_exit(2, name);
}

void			ft_ls(char *path, t_arg *arg, int shwpth, char *name)
{
	t_default	rep;
	t_file		*file;
	DIR			*repo;

	arg->d_showed++;
	rep.shpth = (shwpth == TRUE || shwpth == 3) ? TRUE : FALSE ;
	rep.path = path;
	rep.name = name;
	rep.isltar = shwpth > TRUE ? TRUE : FALSE ;
	if ((repo = opendir(path)) == NULL)
	{
		ft_ctopdir(arg, rep, name);
		return ;
	}
	if ((file = ft_readrep(&rep, repo)) == NULL)
		ft_exit(0, "");
	if ((closedir(repo)) == -1)
		ft_exit(2, rep.path);
	file = ft_sortlst(file, *arg);
	ft_display(&rep, file, *arg);
	if (arg->arg_R_ == TRUE)
		ft_readdir(file, arg);
	ft_dellst(&file);
}