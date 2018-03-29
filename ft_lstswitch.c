/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswitch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 23:20:39 by apruvost          #+#    #+#             */
/*   Updated: 2018/03/22 00:51:49 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_lstswitch(t_file *start_file, t_file *curr_file,
						t_file *next_file)
{
	t_file 	*tmp;
	t_file	*prev_file;

	if (curr_file == start_file)
	{
		start_file->next = next_file->next;
		next_file->next = start_file;
		tmp = start_file;
		start_file = next_file;
		next_file = tmp;
	}
	else
	{
		prev_file = start_file;
		while (prev_file->next != curr_file)
			prev_file = prev_file->next;
		prev_file->next = next_file;
		curr_file->next = next_file->next;
		next_file->next = curr_file;
		tmp = curr_file;
		curr_file = next_file;
		next_file = tmp;
	}
}