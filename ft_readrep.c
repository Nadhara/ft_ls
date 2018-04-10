/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readrep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:41:25 by apruvost          #+#    #+#             */
/*   Updated: 2018/04/07 01:25:37 by apruvost         ###   ########.fr       */
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
	while ((file = readdir(repo)) != NULL)
	{
		if ((curr_file = ft_newfile(file->d_name, realpath)) == NULL)
			ft_exit(1);
		ft_getinfo(curr_file);
		start_file = ft_addfile(start_file, curr_file);
		curr_file = NULL;
	}
	ft_strdel(&realpath);
	return (start_file);
}