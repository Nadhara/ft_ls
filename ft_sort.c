/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 13:22:08 by apruvost          #+#    #+#             */
/*   Updated: 2018/05/21 18:41:25 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_file	*ft_sorttt(t_file *start_file, t_file *curr_file, int *ismod)
{
	if (curr_file->stats->st_mtime >
		curr_file->next->stats->st_mtime)
	{
		start_file = ft_lstswitch(start_file, curr_file, curr_file->next);
		*ismod += 1;
	}
	else if (curr_file->stats->st_mtime ==
		curr_file->next->stats->st_mtime)
	{	
		if (ft_strcmp(curr_file->name, curr_file->next->name) < 0)
		{
			start_file = ft_lstswitch(start_file, curr_file, curr_file->next);
			*ismod += 1;
		}
	}
	return (start_file);
}

static t_file	*ft_sortt(t_file *start_file, t_file *curr_file, int *ismod)
{
	if (curr_file->stats->st_mtime <
		curr_file->next->stats->st_mtime)
	{
		start_file = ft_lstswitch(start_file, curr_file, curr_file->next);
		*ismod += 1;
	}
	else if (curr_file->stats->st_mtime ==
		curr_file->next->stats->st_mtime)
	{
		if (ft_strcmp(curr_file->name, curr_file->next->name) > 0)
		{
			start_file = ft_lstswitch(start_file, curr_file, curr_file->next);
			*ismod += 1;
		}
	}
	return (start_file);
}

static t_file	*ft_sort(t_file *start_file, t_file *curr_file, t_arg arg,
						int *ismod)
{
	if (arg.arg_r_ == FALSE && arg.arg_t_ == FALSE)
	{
		if (ft_strcmp(curr_file->name, curr_file->next->name) > 0)
		{
			start_file = ft_lstswitch(start_file, curr_file, curr_file->next);
			*ismod += 1;
		}
	}
	else if (arg.arg_r_ == TRUE && arg.arg_t_ == FALSE)
	{
		if (ft_strcmp(curr_file->name, curr_file->next->name) < 0)
		{
			start_file = ft_lstswitch(start_file, curr_file, curr_file->next);
			*ismod += 1;
		}
	}
	else if (arg.arg_r_ == FALSE && arg.arg_t_ == TRUE)
		start_file = ft_sortt(start_file, curr_file, ismod);
	else if (arg.arg_r_ == TRUE && arg.arg_t_ == TRUE)
		start_file = ft_sorttt(start_file, curr_file, ismod);
	return (start_file);
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
				start_file = ft_sort(start_file, curr_file, arg, &ismod);
				if (curr_file->next != NULL)
					curr_file = curr_file->next;
			}
		}
	}
	return (start_file);
}