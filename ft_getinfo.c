/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getinfo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:30:42 by apruvost          #+#    #+#             */
/*   Updated: 2018/07/12 16:56:40 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_getpermss(mode_t mode, char *str)
{
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
}

static char			*ft_getperms(mode_t mode)
{
	char 			*str;

	str = malloc(sizeof(char) * 11);
	str[10] = '\0';
	str[9] = ' ';
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
	ft_getpermss(mode, str);
	ft_getspeperm(mode, str);
	return (str);
}

static char			ft_gettype(mode_t mode)
{
	if ((mode & S_IFMT) == S_IFDIR)
		return ('d');
	else if ((mode & S_IFMT) == S_IFREG)
		return ('-');
	else if ((mode & S_IFMT) == S_IFBLK)
		return ('b');
	else if ((mode & S_IFMT) == S_IFCHR)
		return ('c');
	else if ((mode & S_IFMT) == S_IFIFO)
		return ('p');
	else if ((mode & S_IFMT) == S_IFLNK)
		return ('l');
	else if ((mode & S_IFMT) == S_IFSOCK)
		return ('s');
	return ('-');
}

static int			ft_getusgr(t_file *file)
{
	struct passwd	*usn;
	struct group	*grn;

	if ((usn = getpwuid(file->stats->st_uid)) == NULL)
		file->nuser = ft_itoa(file->stats->st_uid);
	else
	{
		if ((file->nuser = ft_strdup(usn->pw_name)) == NULL)
			ft_exit(0, file->name);
	}
	if ((grn = getgrgid(file->stats->st_gid)) == NULL)
		file->ngroup = ft_itoa(file->stats->st_gid);
	else
	{
		if ((file->ngroup = ft_strdup(grn->gr_name)) == NULL)
			ft_exit(0, file->name);
	}
	return (1);
}

void				ft_getinfo(t_file *file)
{
	if ((lstat(file->path, file->stats)) == 0)
	{
		file->isdata = 1;
		file->type = ft_gettype(file->stats->st_mode);
		file->perms = ft_getperms(file->stats->st_mode);
		if ((file->mtime = ft_strdup(ctime(&(file->stats->st_mtime)))) == NULL)
		{
			ft_exit(0, "");
			file->isdata = 3;
		}
		file->fttime = file->stats->st_mtime;
		if ((ft_getusgr(file)) == 0)
			ft_exit(2, file->name);
	}
	else
	{
		file->isdata = 0;
		ft_exit(2, file->name);
	}
}