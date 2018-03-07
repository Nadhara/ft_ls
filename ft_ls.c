/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:28:42 by apruvost          #+#    #+#             */
/*   Updated: 2018/03/07 16:20:38 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <grp.h>

char	*get_type(mode_t mode)
{
	if ((mode & S_IFMT) == S_IFDIR)
		return ("Directory");
	else if ((mode & S_IFMT) == S_IFBLK)
		return ("Block device");
	else if ((mode & S_IFMT) == S_IFCHR)
		return ("Character device");
	else if ((mode & S_IFMT) == S_IFIFO)
		return ("FIFO / Pipe");
	else if ((mode & S_IFMT) == S_IFREG)
		return ("File");
	else if ((mode & S_IFMT) == S_IFLNK)
		return ("Symbolic link");
	else if ((mode & S_IFMT) == S_IFSOCK)
		return ("Socket");
	return ("");
}

void	more_info(struct dirent *file)
{
	struct stat 	*info;
	struct passwd 	*yo;
	struct group	*poto;

	yo = NULL;
	poto = NULL;
	info = malloc(sizeof(struct stat));
	if ((stat(file->d_name, info)) == 0)
	{
		ft_printf("Type : %s\n", get_type(info->st_mode));
		yo = getpwuid(info->st_uid);
		ft_printf("User : %s\n", yo->pw_name);
		poto = getgrgid(info->st_gid);
		ft_printf("Group : %s\n", poto->gr_name);
	} else
		perror(strerror(errno));
}

int		main(void)
{
	DIR 			*dirp;
	struct dirent 	*file;

	dirp = opendir(".");
	while ((file = readdir(dirp)) != NULL)
		{
			ft_printf("Name : %s\n", file->d_name);
			more_info(file);
			ft_printf("\n");
		}
	closedir(dirp);
	return (0);
}