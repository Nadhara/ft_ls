/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iflink.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 15:23:31 by apruvost          #+#    #+#             */
/*   Updated: 2018/07/12 13:09:19 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_iflink(t_file *file, t_arg *arg)
{
	ssize_t	len;

	file->isltard = FALSE;
	if (file->type == 'l' && file->isdata != 0)
	{
		if ((len = readlink(file->path, file->ltarname, 1023)) == -1)
			return (FALSE);
		file->ltarname[len] = '\0';
		if ((file->tarstat = (struct stat *)malloc(sizeof(struct stat)))
			== NULL)
			ft_exit(0, "");
		if ((stat(file->name, file->tarstat)) == 0)
		{
			if ((file->tarstat->st_mode & S_IFMT) == S_IFDIR)
				file->isltard = TRUE;
		}
		else
			return (FALSE);
		ft_memdel((void **)&(file->tarstat));
		if (file->isltard == TRUE && arg->arg_l_ == TRUE)
			file->isltard = FALSE;
	}
	return (file->isltard);
}