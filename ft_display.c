/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 06:53:13 by apruvost          #+#    #+#             */
/*   Updated: 2018/05/31 10:40:13 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		*ft_linktar(t_file *file)
{
	char		*buf;
	char		*res;

	buf = NULL;
	file->didfail = 0;
	if (file->type != 'l')
		return ("");
	if ((buf = (char *)malloc(file->stats->st_size + 1)) == NULL)
	{
		file->didfail = 1;
		return ("");
	}
	buf[file->stats->st_size] = '\0';
	if ((readlink(file->path, buf, file->stats->st_size)) == -1)
	{
		file->didfail = 1;
		return ("");
	}
	res = ft_strjoin(" -> ", buf);
	ft_strdel(&buf);
	return (res);
}

static void		ft_dismore(t_file *file, t_default *wep)
{
	char 		*spl;
	char		*sps;
	char		*spu;
	char		*spg;
	char		*ltar;
	
	file->mtime[16] = '\0';
	ft_printf("%c%s %s%d %s%s  %s%s  %s%l %s %s%s\n",file->type, file->perms,
		spl = ft_nbspl(file, wep), file->stats->st_nlink,
		file->nuser->pw_name, spu = ft_nbspu(file, wep),
		file->ngroup->gr_name, spg = ft_nbspg(file, wep),
		sps = ft_nbsps(file, wep), file->stats->st_size,
		&(file->mtime[4]), file->name, ltar = ft_linktar(file));
	ft_strdel(&spl);
	ft_strdel(&sps);
	ft_strdel(&spu);
	ft_strdel(&spg);
	if (file->type == 'l' && file->didfail == 0)
		ft_strdel(&ltar);
}

void			ft_display(t_default *rep, t_file *start_file, t_arg arg)
{
	t_file		*file;

	file = start_file;
	if (arg.d_showed > 1)
		ft_putchar('\n');
	if (rep->shpth == TRUE)
		ft_printf("%s:\n", rep->path);
	if (arg.arg_l_ == TRUE)
	{
		ft_printf("total %d\n", ft_getblktot(file, arg));
		ft_getmaxsl(file, rep, arg);
	}
	while (file != NULL)
	{
		if (!(file->name[0] == '.' && arg.arg_a_ == FALSE))
		{
			if (arg.arg_l_ == FALSE)
				ft_printf("%s\n",file->name);
			else
			ft_dismore(file, rep);
		}
		file = file->next;
	}
}

void			ft_showfiles(t_arg *arg)
{
	t_file		*file;
	t_default	yep;

	file = arg->args;
	if (arg->arg_l_ == TRUE)
		ft_getmaxsl(file, &yep, *arg);
	while (file != NULL)
	{
		if (!((file->name[0] == '.' && arg->arg_a_ == FALSE) ||
			file->type == 'd' || file->isdata == 0))
		{
			arg->d_showed++;
			if (arg->arg_l_ == FALSE)
				ft_printf("%s\n",file->name);
			else
				ft_dismore(file, &yep);
		}
		file = file->next;
	}	
}