/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 18:59:11 by apruvost          #+#    #+#             */
/*   Updated: 2018/04/11 16:37:51 by apruvost         ###   ########.fr       */
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
					ft_ls(file->path, arg, TRUE);
			}
			else if (file->name[0] != '.')
				ft_ls(file->path, arg, TRUE);
		}
		file = file->next;
	}
}

void			ft_ls(char *path, t_arg *arg, int shwpth)
{
	t_default	rep;
	t_file		*file;
	DIR			*repo;

	arg->d_showed++;
	rep.shpth = shwpth ? TRUE : FALSE ;
	rep.path = path;
	if ((repo = opendir(path)) == NULL)
	{
		ft_printf("%s%s\n", (arg->d_showed > 1 ? "\n" : ""), rep.path);
		perror(strerror(errno));
		return ;
	}
	if ((file = ft_readrep(&rep, repo)) == NULL)
	{
		ft_exit(1);
		return ;
	}
	if ((closedir(repo)) == -1)
		perror(strerror(errno));
	file = ft_sortlst(file, *arg);
	ft_display(rep, file, *arg);
	if (arg->arg_R_ == TRUE)
		ft_readdir(file, arg);
	ft_dellst(&file);
}