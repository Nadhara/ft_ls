/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:18:29 by apruvost          #+#    #+#             */
/*   Updated: 2018/01/18 14:34:29 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static char			*ft_readline(int fd, char **buf, char *end)
{
	char	str[GNL_BUFF_SIZE + 1];
	char	*bin;
	int		len;

	while ((len = read(fd, str, GNL_BUFF_SIZE)))
	{
		str[len] = '\0';
		bin = *buf;
		if ((*buf = ft_strjoin(*buf, str)) == NULL)
			return (NULL);
		free(bin);
		if ((end = ft_strchr(*buf, '\n')))
			return (end);
	}
	return (0);
}

static t_list		*ft_isfd(int fd, t_list **lstfd)
{
	t_list	*curr_fd;

	curr_fd = *lstfd;
	while (curr_fd != NULL)
	{
		if ((int)curr_fd->content_size == fd)
			return (curr_fd);
		curr_fd = curr_fd->next;
	}
	if ((curr_fd = ft_lstnew("", 1)) == NULL)
		return (NULL);
	curr_fd->content_size = fd;
	ft_lstadd(lstfd, curr_fd);
	return (curr_fd);
}

int					ft_get_next_line(const int fd, char **line)
{
	static t_list	*lstfd;
	t_list			*curr_fd;
	char			*end;
	char			*bin;

	if (!(curr_fd = ft_isfd(fd, &lstfd)) || fd < 0 || line == NULL ||
										read(fd, curr_fd->content, 0) < 0)
		return (-1);
	end = ft_strchr(curr_fd->content, '\n');
	if (end == NULL)
		end = ft_readline(fd, (char **)&curr_fd->content, end);
	if (end != NULL)
	{
		*end = '\0';
		*line = ft_strdup((char *)curr_fd->content);
		bin = curr_fd->content;
		curr_fd->content = ft_strdup(end + 1);
		free(bin);
		return (1);
	}
	*line = ft_strdup((char *)curr_fd->content);
	free(curr_fd->content);
	curr_fd->content = ft_strnew(0);
	return ((**line) ? 1 : 0);
}
