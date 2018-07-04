/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 08:00:51 by apruvost          #+#    #+#             */
/*   Updated: 2018/07/04 19:23:08 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_exit(int error, char *name)
{
	ft_putstr_fd("ft_ls: ", 2);
	if (error == 0)
	{
		ft_dprintf(2, "ft_ls: Can't allocate enough memory\n");
		exit(1);
	}
	else if (error == 1)
	{
		ft_dprintf(2, "illegal option\n");
		exit(1);
	}
	else
		ft_dprintf(2, "%s: %s\n", name, strerror(errno));
}