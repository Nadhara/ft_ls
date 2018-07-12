/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 02:57:26 by apruvost          #+#    #+#             */
/*   Updated: 2018/07/12 13:39:44 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_isarg(char c, t_arg *arg, int i, int *isarg)
{
	if (c == 'l')
		arg->arg_l_ = TRUE;
	else if (c == 'a')
		arg->arg_a_ = TRUE;
	else if (c == 'R')
		arg->arg_R_ = TRUE;
	else if (c == 'r')
		arg->arg_r_ = TRUE;
	else if (c == 't')
		arg->arg_t_ = TRUE;
	else if (c == '-' && i == 1)
	{
		*isarg = FALSE;
		return (1);
	}
	else if (c != '1')
		return (0);
	return (1);
}

void		ft_getopt(char *str, t_arg *arg, int *isarg)
{
	size_t	len;
	size_t i;

	len  = ft_strlen(str);
	i = 1;
	while (i < len)
	{
		if ((ft_isarg(str[i], arg, i, isarg)) == 0)
		{
			ft_exit(1, &(str[i]));
			return ;
		}
		i++;
		if (*isarg == FALSE)
		{
			if (str[i] != '\0')
				ft_exit(1, "-");
			return ;
		}
	}
}