/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 15:59:18 by apruvost          #+#    #+#             */
/*   Updated: 2018/08/22 13:49:15 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_getfargs(int argc, char **argv, t_arg *arg, int i)
{
	t_file		*curr_file;

	argv = ft_sortarg(argc, argv, i);
	while (i < argc)
	{
		if (argv[i][0] == '~' || argv[i][0] == '/' ||
			(argv[i][0] == '.' && (argv[i][1] == '\0' || argv[i][1] == '/')))
		{
			if ((curr_file = ft_newfile(argv[i], "")) == NULL)
				ft_exit(0, "");
		}
		else
		{
			if ((curr_file = ft_newfile(argv[i], "")) == NULL)
				ft_exit(0, "");
		}
		ft_getinfo(curr_file);
		arg->args = ft_addfile(arg->args, curr_file);
		curr_file = NULL;
		i++;
	}
}

static void		ft_getargs(int argc, char **argv, t_arg *arg)
{
	int			isarg;
	int			i;

	i = 1;
	isarg = TRUE;
	ft_initargs(arg);
	while (isarg == TRUE && i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] != '\0')
		{
			ft_getopt(argv[i], arg, &isarg);
			i++;
		}
		else
			isarg = FALSE;
	}
	arg->nb_file = argc - i;
	arg->d_showed = 0;
	arg->args = NULL;
	ft_getfargs(argc, argv, arg, i);
	arg->args = ft_sortlst(arg->args, *arg);
	ft_showfiles(arg);
}

static void		ft_noarg(t_arg *arg)
{
	arg->arg_a_ = FALSE;
	arg->arg_l_ = FALSE;
	arg->arg_r_ = FALSE;
	arg->arg_br_ = FALSE;
	arg->arg_t_ = FALSE;
	arg->nb_file = FALSE;
	arg->args = NULL;
	arg->d_showed = 0;
}

static void		ft_lsargs(t_file *curr_file, t_arg arg)
{
	while (curr_file != NULL)
	{
		if (curr_file->type == 'd' && curr_file->isdata != 0)
			ft_ls(curr_file->path, &arg,
					((arg.nb_file > 1) ? TRUE : FALSE), curr_file->name);
		else if (curr_file->isltard == TRUE)
			ft_ls(curr_file->ltarname, &arg,
				((arg.nb_file > 1) ? 3 : 2), curr_file->name);
		curr_file = curr_file->next;
	}
}

int				main(int argc, char **argv)
{
	t_arg		arg;
	t_file		*curr_file;

	if (argc == 1)
		ft_noarg(&arg);
	else
		ft_getargs(argc, argv, &arg);
	if (arg.nb_file == 0)
		ft_ls(ft_strdup("./"), &arg, 0, ".");
	else
	{
		curr_file = arg.args;
		ft_lsargs(curr_file, arg);
	}
	if (arg.args != NULL)
		ft_dellst(&arg.args);
	exit(0);
	return (0);
}
