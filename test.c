/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:28:42 by apruvost          #+#    #+#             */
/*   Updated: 2018/03/22 09:30:52 by apruvost         ###   ########.fr       */
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
#include <time.h>

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

char	*get_perms(mode_t mode)
{
	char *str;

	str = malloc(sizeof(char) * 10);
	str[9] = '\0';
	if ((mode & S_IRUSR) == S_IRUSR)
		str[0] = 'r';
	else
		str[0] = '-';
	if ((mode & S_IWUSR) == S_IWUSR)
		str[1] = 'w';
	else
		str[1] = '-';
	if ((mode & S_IXUSR) == S_IXUSR)
		str[2] = 'x';
	else
		str[2] = '-';
	if ((mode & S_IRGRP) == S_IRGRP)
		str[3] = 'r';
	else
		str[3] = '-';
	if ((mode & S_IWGRP) == S_IWGRP)
		str[4] = 'w';
	else
		str[4] = '-';
	if ((mode & S_IXGRP) == S_IXGRP)
		str[5] = 'x';
	else
		str[5] = '-';
	if ((mode & S_IROTH) == S_IROTH)
		str[6] = 'r';
	else
		str[6] = '-';
	if ((mode & S_IWOTH) == S_IWOTH)
		str[7] = 'w';
	else
		str[7] = '-';
	if ((mode & S_IXOTH) == S_IXOTH)
		str[8] = 'x';
	else	
		str[8] = '-';
	return (str);
	}

void	more_info(struct dirent *file)
{
	struct stat 	*info;
	struct passwd 	*yo;
	struct group	*poto;
	char			*bin;

	yo = NULL;
	poto = NULL;
	info = malloc(sizeof(struct stat));
	if ((stat(file->d_name, info)) == 0)
	{
		ft_printf("Type : %s\n", get_type(info->st_mode));
		ft_printf("Perms : %s\n", (bin = get_perms(info->st_mode)));
		ft_printf("Last modified : %s", ctime(&(info->st_mtimespec.tv_sec)));
		ft_printf("Size : %d bits\n", info->st_size);
		ft_printf("Number of hard link : %d\n", info->st_nlink);
		yo = getpwuid(info->st_uid);
		ft_printf("User : %s\n", yo->pw_name);
		poto = getgrgid(info->st_gid);
		ft_printf("Group : %s\n", poto->gr_name);
		ft_strdel(&bin);
		ft_memdel((void *)&info);
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