/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readrep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:41:25 by apruvost          #+#    #+#             */
/*   Updated: 2018/03/22 11:52:33 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char			*ft_setrealpath(char *path)
{
	char			*rpath;

	rpath = NULL;
	if (path[ft_strlen(path) - 1] != '/')
	{
		if ((rpath = ft_strjoin(path, "/")) == NULL)
			return (NULL);
	}
	else
	{
		if ((rpath = strdup(path)) == NULL)
			return (NULL);
	}
	return (rpath);
}

t_file				*ft_readrep(t_default *rep, DIR *repo)
{
	char			*realpath;
	t_file			*start_file;
	t_file			*curr_file;
	struct dirent	*file;

	start_file = NULL;
	if ((realpath = ft_setrealpath(rep->path)) == NULL)
	{
		ft_exit(1);
		return (NULL);
	}
	ft_printf("realpath = %s\n---------------------\n", realpath);
	while ((file = readdir(repo)) != NULL)
	{
		ft_printf("-----------------------------------\n");
		if ((curr_file = ft_newfile(file->d_name, realpath)) == NULL)
			ft_exit(1);
		ft_getinfo(curr_file);
		start_file = ft_addfile(start_file, curr_file);
		ft_printf("File added\n");
		curr_file = NULL;
		ft_printf("-----------------------------------\n");
	}
	ft_strdel(&realpath);
	return (start_file);
}