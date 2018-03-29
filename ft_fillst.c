/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:09:46 by apruvost          #+#    #+#             */
/*   Updated: 2018/03/22 10:44:10 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_sortt(t_file *start_file, t_file *curr_file, t_arg arg,
						int *ismod)
{
	if (arg.arg_r_ == FALSE && arg.arg_t_ == TRUE)
	{
		if (curr_file->stats->st_mtimespec.tv_sec >
			curr_file->next->stats->st_mtimespec.tv_sec)
		{
			ft_lstswitch(start_file, curr_file, curr_file->next);
			*ismod += 1;
		}
	}
	else if (arg.arg_r_ == TRUE && arg.arg_t_ == TRUE)
	{
		if (curr_file->stats->st_mtimespec.tv_sec <
			curr_file->next->stats->st_mtimespec.tv_sec)
		{
			ft_lstswitch(start_file, curr_file, curr_file->next);
			*ismod += 1;
		}
	}
}

static void		ft_sort(t_file *start_file, t_file *curr_file, t_arg arg,
						int *ismod)
{
	if (arg.arg_r_ == FALSE && arg.arg_t_ == FALSE)
	{
		if (ft_strcmp(curr_file->name, curr_file->next->name) < 0)
		{
			ft_lstswitch(start_file, curr_file, curr_file->next);
			*ismod += 1;
		}
	}
	else if (arg.arg_r_ == TRUE && arg.arg_t_ == FALSE)
	{
		if (ft_strcmp(curr_file->name, curr_file->next->name) > 0)
		{
			ft_lstswitch(start_file, curr_file, curr_file->next);
			*ismod += 1;
		}
	}
	else
		ft_sortt(start_file, curr_file, arg, ismod);
}

t_file		*ft_sortlst(t_file *start_file, t_arg arg)
{
	int		ismod;
	t_file	*curr_file;

	ismod = 1;
	if (start_file != NULL)
	{
		while (ismod != 0)
		{
			curr_file = start_file;
			ismod = 0;
			while (curr_file->next != NULL)
			{
				ft_sort(start_file, curr_file, arg,
					&ismod);
				curr_file = curr_file->next;
			}
		}
	}
	return (start_file);
}

t_file		*ft_addfile(t_file *start_file, t_file *curr_file)
{
	ft_printf("adding file to list\n");
	curr_file->next = start_file;
	return (curr_file);
}

t_file		*ft_newfile(char *nname, char *reppath)
{
	t_file	*file;

	ft_printf("Creating new file\n");
	if ((file = (t_file *)malloc(sizeof(file))) == NULL)
		return (NULL);
	if ((file->name = ft_strdup(nname)) == NULL)
		return (NULL);
	if ((file->path = ft_strjoin(reppath, file->name)) == NULL)
		return (NULL);
	if ((file->stats = (struct stat *)malloc(sizeof(struct stat))) == NULL)
		return (NULL);
	if ((file->lfstats = (struct stat *)malloc(sizeof(struct stat))) == NULL)
		return (NULL);
	file->next = NULL;
	ft_printf("New file created\n");
	return (file);
}