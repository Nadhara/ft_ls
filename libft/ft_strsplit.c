/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:12:58 by apruvost          #+#    #+#             */
/*   Updated: 2017/11/22 12:51:19 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		wordnumber(const char *s, char c)
{
	int		word;
	int		i;
	int		isword;

	i = 0;
	word = 0;
	isword = 0;
	while (s[i])
	{
		if (s[i] == c)
			isword = 0;
		else if (s[i] != c && isword == 0)
		{
			isword = 1;
			word++;
		}
		i++;
	}
	return (word);
}

static int		word_len(const char *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	while (s[i + j] != c && s[i + j] != 0)
		j++;
	return (i + j);
}

static char		*add_word(char const *s, char c, char *str)
{
	int		i;
	int		k;
	int		len;
	char	*dst;

	i = 0;
	k = 0;
	while (s[i] == c)
		i++;
	len = word_len(&s[i], c);
	dst = str;
	if ((dst = (char *)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	while (k < len)
	{
		dst[k] = s[i + k];
		k++;
	}
	dst[k] = '\0';
	return (dst);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		wnb;
	int		j;
	int		i;

	if (s)
	{
		i = 0;
		j = 0;
		wnb = wordnumber(s, c);
		if ((str = (char **)malloc(sizeof(char *) * (wnb + 1))) == NULL)
			return (NULL);
		while (j < wnb)
		{
			if ((str[j] = add_word(&s[i], c, str[j])) == NULL)
				return (NULL);
			j++;
			i += word_len(&s[i], c);
		}
		str[j] = NULL;
		return (str);
	}
	return (NULL);
}
