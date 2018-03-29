/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:05:14 by apruvost          #+#    #+#             */
/*   Updated: 2018/03/22 11:32:08 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H

# define TRUE 1
# define FALSE 0

# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <sys/types.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <grp.h>
# include <time.h>
# include "libft/libft.h"

typedef struct		s_file
{
	char			*name;
	char			*path;
	char			type;
	char			*perms;
	char			*mtime;

	struct stat 	*stats;
	struct stat		*lfstats;
	struct passwd 	*nuser;
	struct group	*ngroup;

	struct s_file	*next;
}					t_file;

typedef struct		s_default
{
	char			*path;
	int				shpth;
	int				error;

}					t_default;

typedef struct		s_arg
{
	int				arg_l_;
	int				arg_R_;
	int				arg_a_;
	int				arg_r_;
	int				arg_t_;
	int				nb_file;
	t_file			*args;
}					t_arg;

void				ft_getopt(char *str, t_arg *arg);
void				ft_ls(char *path, t_arg arg, int shwpth);

void				ft_showfiles(t_arg *arg);
void				ft_display(t_default rep, t_file *start_file, t_arg arg);

t_file				*ft_readrep(t_default *rep, DIR *repo);
void				ft_getinfo(t_file *curr_file);

t_file				*ft_newfile(char *nname, char *reppath);
t_file				*ft_addfile(t_file *start_file, t_file *curr_file);
t_file				*ft_sortlst(t_file *start_file, t_arg arg);
void				ft_lstswitch(t_file *start_file, t_file *curr_file,
								t_file *next_file);
void				ft_dellst(t_file **start_file);

void				ft_exit(int error);

#endif