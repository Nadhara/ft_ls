/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswitch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 23:20:39 by apruvost          #+#    #+#             */
/*   Updated: 2018/04/11 13:31:36 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*ft_lstswitch(t_file *start_file, t_file *curr_file,
						t_file *next_file)
{
	t_file	*prev_file;

	if (curr_file == start_file)
	{
		curr_file->next = next_file->next;
		next_file->next = curr_file;
		return (next_file);
	}
	else
	{
		prev_file = start_file;
		while (prev_file->next != curr_file)
			prev_file = prev_file->next;
		prev_file->next = next_file;
		curr_file->next = next_file->next;
		next_file->next = curr_file;
	}
	return (start_file);
}