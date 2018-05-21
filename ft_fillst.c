/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:09:46 by apruvost          #+#    #+#             */
/*   Updated: 2018/05/21 19:45:05 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*ft_addfile(t_file *start_file, t_file *curr_file)
{
	curr_file->next = start_file;
	return (curr_file);
}

t_file		*ft_newfile(char *nname, char *reppath)
{
	t_file	*file;

	if ((file = (t_file *)malloc(sizeof(t_file))) == NULL)
		ft_exit(0, "");
	if ((file->name = ft_strdup(nname)) == NULL)
		ft_exit(0, "");
	if ((file->path = ft_strjoin(reppath, file->name)) == NULL)
		ft_exit(0, "");
	if ((file->stats = (struct stat *)malloc(sizeof(struct stat))) == NULL)
		ft_exit(0, "");
	file->next = NULL;
	return (file);
}