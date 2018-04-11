/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:09:46 by apruvost          #+#    #+#             */
/*   Updated: 2018/04/11 16:42:25 by apruvost         ###   ########.fr       */
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
		return (NULL);
	if ((file->name = ft_strdup(nname)) == NULL)
		return (NULL);
	if ((file->path = ft_strjoin(reppath, file->name)) == NULL)
		return (NULL);
	if ((file->stats = (struct stat *)malloc(sizeof(struct stat))) == NULL)
		return (NULL);
	if ((file->lfstats = (struct stat *)malloc(sizeof(struct stat))) == NULL)
		return (NULL);
	file->next = NULL;
	return (file);
}