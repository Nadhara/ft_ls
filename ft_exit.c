/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 08:00:51 by apruvost          #+#    #+#             */
/*   Updated: 2018/03/22 08:06:49 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_exit(int error)
{
	if (error == 1)
	{
		ft_putstr_fd("error : Can't allocate enough memory\n", 2);
		exit(1);
	}
}