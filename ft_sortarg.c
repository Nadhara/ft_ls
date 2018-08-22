/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortarg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 14:33:03 by apruvost          #+#    #+#             */
/*   Updated: 2018/08/01 19:40:30 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		**ft_sortarg(int argc, char **argv, int i)
{
	char	*bin;
	int		j;
	int		ismod;

	ismod = TRUE;
	while (ismod != FALSE)
	{
		ismod = 0;
		j = i;
		while (j < (argc - 1))
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
			{
				bin = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = bin;
				ismod++;
			}
			j++;
		}
	}
	return (argv);
}
