/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 13:22:08 by apruvost          #+#    #+#             */
/*   Updated: 2018/07/04 19:05:39 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_comparenext(t_file *left, t_file *right, t_arg arg)
{
	if (arg.arg_r_ == TRUE && arg.arg_t_ == TRUE)
	{
		if (left->stats->st_mtime < right->stats->st_mtime)
			return (1);
		else if (left->stats->st_mtime == right->stats->st_mtime)
		{	
			if (ft_strcmp(left->name, right->name) < 0)
				return (1);
		}
	}
	return (0);
}

static int		ft_compare(t_file *left, t_file *right, t_arg arg)
{
	if (arg.arg_r_ == FALSE && arg.arg_t_ == FALSE)
	{
		if (ft_strcmp(left->name, right->name) < 0)
			return (1);
	}
	else if (arg.arg_r_ == TRUE && arg.arg_t_ == FALSE)
	{
		if (ft_strcmp(left->name, right->name) > 0)
			return (1);
	}
	else if (arg.arg_r_ == FALSE && arg.arg_t_ == TRUE)
	{
		if (left->stats->st_mtime > right->stats->st_mtime)
			return (1);
		else if (left->stats->st_mtime == right->stats->st_mtime)
		{
			if (ft_strcmp(left->name, right->name) < 0)
				return (1);
		}
	}
	return (ft_comparenext(left, right, arg));
}

static t_file	*ft_merge(t_file *left, t_file *right, t_arg arg)
{
	t_file		*result;
	t_file		*nextf;

	result = NULL;
	while (left != NULL && right != NULL)
	{
		if (ft_compare(left, right, arg) == 1)
		{
			nextf = left->next;
			result = ft_addsrtfile(result, left);
			left = nextf;
		}
		else
		{
			nextf = right->next;
			result = ft_addsrtfile(result, right);
			right = nextf;
		}
		nextf = NULL;
	}
	if (left != NULL)
		result = ft_addfile(result, left);
	if (right != NULL)
		result = ft_addfile(result, right);
	return (result);
}

int				ft_getlstlen(t_file *start_file)
{
	t_file		*file;
	int			i;

	i = 0;
	file = start_file;
	if (file == NULL)
		return (i);
	while (file != NULL)
	{
		i++;
		file = file->next;
	}
	return (i);
}

t_file			*ft_sortlst(t_file *file, t_arg arg)
{
	int			len;
	int			i;
	t_file		*nextf;
	t_file		*left;
	t_file		*right;

	if (((len = ft_getlstlen(file))) <= 1)
		return (file);
	left = NULL;
	right = NULL;
	i = 0;
	while (file != NULL)
	{
		nextf = file->next;
		if (i < (len / 2))
			left = ft_addsrtfile(left, file);
		else
			right = ft_addsrtfile(right, file);
		file = nextf;
		nextf = NULL;
		i++;
	}
	left = ft_sortlst(left, arg);
	right = ft_sortlst(right, arg);
	return (ft_merge(left, right, arg));
}