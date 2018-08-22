/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:05:14 by apruvost          #+#    #+#             */
/*   Updated: 2018/08/22 13:47:08 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H

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
	time_t			fttime;
	int				timenorm;
	char			*mtime;
	char			*mtimechr;
	char			*nuser;
	char			*ngroup;

	struct stat		*stats;

	struct stat		*tarstat;
	int				isltard;
	char			ltarname[1024];

	int				isdata;
	int				didfail;
	struct s_file	*next;
}					t_file;

typedef struct		s_default
{
	char			*path;
	char			*name;
	int				shpth;
	int				isltar;
	int				error;
	int				maxlk;
	int				maxlklen;
	long			maxsz;
	int				maxszlen;
	int				maxmaj;
	int				maxmajlen;
	int				maxmin;
	int				maxminlen;
	int				maxmajminlen;
	size_t			maxuslen;
	size_t			maxgrplen;
}					t_default;

typedef struct		s_arg
{
	int				arg_l_;
	int				arg_br_;
	int				arg_a_;
	int				arg_r_;
	int				arg_t_;
	int				nb_file;
	int				d_showed;
	t_file			*args;
}					t_arg;

void				ft_getopt(char *str, t_arg *arg, int *isarg);
void				ft_initargs(t_arg *arg);
void				ft_ls(char *path, t_arg *arg, int shwpth, char *name);

char				**ft_sortarg(int argc, char **argv, int i);

void				ft_showfiles(t_arg *arg);
void				ft_display(t_default *rep, t_file *start_file, t_arg arg);
void				ft_getmaxsl(t_file *start_file, t_default *wep, t_arg arg);
int					ft_getblktot(t_file *start_file, t_arg arg);
char				*ft_nbspl(t_file *file, t_default *wep);
char				*ft_nbsps(t_file *file, t_default *wep);
char				*ft_nbspu(t_file *file, t_default *wep);
char				*ft_nbspg(t_file *file, t_default *wep);
char				*ft_nbspmaj(t_file *file, t_default *wep);
char				*ft_nbspmin(t_file *file, t_default *wep);
void				ft_gettimest(t_file *file);

t_file				*ft_readrep(t_default *rep, DIR *repo);
int					ft_getinfo(t_file *curr_file);
void				ft_getspeperm(mode_t mode, char *str);
int					ft_iflink(t_file *file, t_arg *arg);

t_file				*ft_newfile(char *nname, char *reppath);
t_file				*ft_addfile(t_file *start_file, t_file *curr_file);
t_file				*ft_addsrtfile(t_file *start_file, t_file *curr_file);
t_file				*ft_sortlst(t_file *start_file, t_arg arg);
int					ft_getlstlen(t_file *start_file);
void				ft_dellst(t_file **start_file);

void				ft_exit(int error, char *name);

#endif
